'''
Implementation of multi-resolution occupied voxel lists (MROL) 
Author: Julian Ryde and  Nick Hillier
'''
from __future__ import division

import time
import os
import numpy as np

import occupiedlist
import optimization
import util
import poseutil
import quantizer

import cython.fast as fast

#modalfractions = [0.7, 0.8, 0.9, 0.9, 0.9] 

modalfractions = np.repeat(0.3, 5)
topn = 100

# TODO consider pulling in table class from icra2011 code, table.py
def printtable(table_array, width):
    for row in table_array:
        for field in row:
            print '| ' + field.ljust(width),
        print
        
def _cost_min_scipy(objective_func, initialpose, args):
    import scipy.optimize as optimize
    initialpose = initialpose.getTuple()
    returns = optimize.fmin(objective_func, initialpose, args=args, disp=True, full_output=True)
    #returns = optimize.fmin_powell(objective_func, initialpose, args=args, disp=True, full_output=True)
    #returns = optimize.fmin_slsqp(objective_func, initialpose, args=args, full_output=True) # doesn't work?    
    #initpose = np.asarray(initialpose)
    #delta = np.asarray((0.5, 0.5, 0.5, 0.2, 0.2, 0.2))
    #lower = initpose - delta
    #upper = initpose + delta    
    #returns = optimize.anneal(objective_func, initialpose, args=args, lower=lower, upper=upper)
    bestpose = poseutil.Pose3D(X=returns[0])
    cost = returns[1]
    return bestpose, cost

class MROL:
    '''
    Stores voxel indices at multiple resolution occupied voxel lists
    and provides interfaces to add, remove and manipulate the data.
    '''
    def __init__(self, resolution, levels=3):
        # coarse to fine resolutions
        self.factor = 2 # multiplier between the resolutions might have to be an integer?
        resolutions = (pow(self.factor, np.arange(levels))*resolution)[::-1]
        self.mapvoxels = [] # list of occupied voxel lists
        self.maptimes = []
        for i, res in enumerate(resolutions):
            ol = occupiedlist.OccupiedList(res)
            self.mapvoxels.append(ol)
            #self.maptimes.append([]) # TODO

        self.keyframe = set()
        self.feature_range = 8.0
        # range to a good feature density for angular alignment purposes

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        width = 6
        delim = '\t'
        resolutions = (str(m.resolution).rjust(width) for m in self.mapvoxels)
        retstr = 'resolutions:  ' + delim.join(resolutions) + '\nvoxel counts: '
        voxel_counts = (str(len(m)).rjust(width) for m in self.mapvoxels)
        retstr += delim.join(voxel_counts)
        return retstr 
    
    def __len__(self):
        return len(self.mapvoxels)

    def __eq__(self, mrol_map):
        return self.__dict__ == mrol_map.__dict__
        
    def getresolution(self, level=None):
        if level == None: return self.getfinest().resolution
        return self.mapvoxels[level].resolution

    def getpoints(self, level=-1):
        return self.mapvoxels[level].getpoints()

    def getvoxels(self, level=-1):
        return self.mapvoxels[level].getvoxels()

    def getfinest(self):
        '''
        Returns the occupied list with the finest/best resolution it has.
        '''
        return self.mapvoxels[-1]
        
    def addpoints(self, xyzs, timestamp=None, userdata=None, increment=1):
        # TODO do something with timestamps for re-journalling
        # TODO allow userdata to be added as an information field to the voxels 
        # (e.g. RGB)
        # TODO work out how to get the userdata out again (perhaps in 
        # getpoints/getvoxels?)        

        for ol in self.mapvoxels:
            ol.addpoints(xyzs)

        ## add to the finest occupiedlist
        #modified_inds, increments = self.getfinest().addpoints(xyzs, return_modified=True, increment=increment)
        ##modified_inds_finest = modified_inds.copy()
        ## now propagate these modifications to coarser resolutions
        #for ol in self.mapvoxels[-2::-1]:
        #    modified_inds /= self.factor
        #    # TODO slow but hopefully more likely to be correct way
        #    ol._update_voxels(modified_inds, increments)
        ##return modified_inds_finest

    def removepoints(self, xyzs, return_removed=False):
        return self.addpoints(xyzs, increment=-1)
            
    # TODO Reconsider keyframe usage after trajectory class is implemented
    #def setkeyframe(self, xyzs, pose):
    #    xyzs = poseutil.transformPointsTuple(xyzs,pose)
    #    voxel_array = occupiedlist.pointstovoxels(xyzs, self.getresolution(), unique=True)
    #    self.keyframe = set(occupiedlist.hashrows(voxel_array))
    #    
    #def getkeyframeset(self):
    #    return self.keyframe
        
    def optimise_alignment(self, xyzs, initialpose, full_data=False):
        ''' The format of this function allows us to use standard optimizers 
        and arbitrary cost functions from the scipy.optimize library.'''
        dtheta_base = np.radians(0.5)
        if not full_data:
            xyzs_sample = util.volumetricsample(xyzs, self.getfinest().resolution)
        else:
            xyzs_sample = xyzs
        bestpose = initialpose
        for level, ol in enumerate(self.mapvoxels):
            objective_func = ol.cost_func
            #objective_func = self.objectivefuncMROL
            #ol.use_bloom = False
            dtheta = dtheta_base*pow(self.factor,(len(self.mapvoxels)-level-1))
            dx = ol.resolution
            # This helps avoid local minima, but limits accuracy to voxel size 
            # at the finest resolution
            bestpose, cost = optimization.cost_min(objective_func, bestpose, (xyzs_sample,), dx, dtheta, max_iterations=20, verbosity=0)
            #import pydb; pydb.set_trace()
            #bestpose, cost = _cost_min_scipy(objective_func, bestpose, (xyzs_sample,))
        # run it again at the finest resolution with tighter steps to get 
        # sub-voxel accuracy.
        dx = dx*pow(self.factor,-2)
        dtheta = dtheta_base*pow(self.factor,-2)
        if not full_data:
            # Sometimes get better results with the below resampling, but much faster.
            xyzs = util.offsetvolsample(xyzs, self.getfinest().resolution)
        bestpose, cost = optimization.cost_min(objective_func, bestpose, (xyzs,), dx, dtheta, max_iterations=100, verbosity=0)
        return bestpose, cost

    def objectivefuncMROL(self, pose, xyzs):
        '''
        Objective function to be minimised.
        For a list of xyzs, transforms by pose and calculations the cost
        at the various resolutions. If level is specified, only 
        calc at that level.
        '''
        levels = len(self.mapvoxels)
        hits = np.empty(levels)
        resolutions = np.empty(levels)
        for i, ol in enumerate(self.mapvoxels):
            hits[i] = ol.calccollisions(pose, xyzs, query=False)
            resolutions[i] = ol.resolution
        # sort hits from coarse to fine
        new = np.hstack((-np.diff(hits), hits[-1]))
        #weights = np.ones(levels)
        weights = resolutions[-1]/resolutions # same as ..., 1/8, 1/4, 1/2, 1
        #cost = -np.dot(weights, hits)
        cost = -np.dot(weights, new)
        return cost
     
    def calcray(self, ray):    
        ol = self.getfinest()
        hits = ol.segment_ovl(None, ray)[0] 
        if len(hits) > 0:
            vox_hits = occupiedlist.pointstovoxels(hits,ol.resolution,ol.lattice)
            return quantizer.uniquerows(vox_hits, 0)
        else:
            return []
            
    def raytrace(self, pose, length, axis=0):
        '''
        perform a ray-trace from the pose and return all map voxels at the
        base resolution along the ray.
        It traces from any point in the map frame (e.g. the sensor's
        current position) along a ray oriented as per the pose's angular 
        components.
        '''
        res = self.getresolution()/2.
        #import pdb;pdb.set_trace()
        numcells = np.ceil(length/res)+2 # + 1 for 0th point + 1 for end point with poor aligned voxels
        ray = np.zeros([numcells,3])
        ray[:,axis] = np.hstack([0,np.cumsum(np.ones(numcells-1))*res])
        ray = poseutil.check_and_transform_points(ray, pose)[0]
        return self.calcray(ray)
        
    def raytracepts(self, point1, point2, return_extras=False):
        '''
        perform a ray-trace from point1 to point2 and return all map 
        voxels at the base resolution along the ray.
        '''
        res = self.getresolution()#/3.
        point2a = point2 - point1
        range2 = np.sum(point2a**2)
        length = np.sqrt(range2)
        dir_unit = point2a/length
        numcells = int(np.ceil(length/res)+2) # + 1 for 0th point + 1 for last point
        ray = np.zeros([numcells,3])
        ## TODO make this a list comprehension as this loop slows the cast down lots
        #for i in range(numcells):
        #    ray[i] = dir_unit*i*res
        ray_res = length/(numcells-1)
        ray = fast.fillray(numcells, dir_unit, ray_res, ray)
        ray = ray + point1
        if return_extras:
            return self.calcray(ray), length, dir_unit, ray
        else:
            return self.calcray(ray)
        
                
    def add_dilate(self, xyzs):
        self.dilated = occupiedlist.dilate(self.getvoxels())

    def match(self, xyzs, centrepose, spreadpose):
        """Does a global search of the specified pose space.
        Find the possible locations of the occupied list ol in the current 
        occupied list.  Takes an occupied list to match to the current one and 
        two poses."""
        debug = False

        # determines the orientation step size as it relates to occupancy list 
        # resolution
        poses = None
        bestpose = poseutil.Pose3D()

        totaltime = time.time()
        lasttime = time.time()
        #for i in range(len(self.voxels)):
        # volumetric sample and each resolution equivalent to matching two 
        # occupiedlists together but without the double quantisation error
        # TODO think about this number
        #xyzs = util.getsample(xyzs, 1000)

        levels = len(self.mapvoxels)
        table = np.zeros((levels+2, 9), dtype=np.dtype('S8'))
        # header for the table of values of interest
        table[0, :] = "Res modal map    scan   pose  pose  Top     Time  Best".split()
        table[1, :] = "(m) Frac  voxels points count count overlap Taken pose".split()
        for i, mapol in enumerate(self.mapvoxels):
            tablerow = i + 2
            res = mapol.resolution
            deltaposition = res
            deltaorientation = res/self.feature_range # 8
            if poses == None:
                poses = poseutil.uniformposes(centrepose, spreadpose, deltaposition, deltaorientation)
            else:
                poses = poseutil.refineposes(poses, deltaposition, deltaorientation)

            # TODO remove poses outside search space this needs tidying up/thinking about
            #cparr = np.array(centrepose.get())
            #sparr = np.array(spreadpose.get())
            #
            #D = np.array((deltaposition, deltaposition, deltaposition, deltaorientation, deltaorientation, deltaorientation))
            #maxpose = cparr + sparr + D
            #minpose = cparr - sparr - D
            #select = np.logical_and(np.all(poses <= maxpose, 1), np.all(poses >= minpose, 1))
            ##print 'Culling poses: ', len(poses), sum(select)
            #poses = poses[select]
            
            xyzs_sample = util.volumetricsample(xyzs, res)
            table[tablerow, :5] = (res, modalfractions[i], len(mapol), len(xyzs_sample), len(poses))

            # TODO TIME consuming line
            #overlaps = self.getoverlaps(ol, i, poses)
            overlaps = []
            for pose in poses:
                #overlap = np.sum(mapol.calccollisions(pose, xyzs, query=True))
                overlap = mapol.calccollisions(pose, xyzs, query=False)
                overlaps.append(overlap)
                #overlaps.append(-self.objectivefuncMROL(pose, xyzs_sample))
            overlaps = np.asarray(overlaps)

            ind_max = np.argmax(overlaps)
            bestpose.set(poses[ind_max])
            bestoverlap = overlaps[ind_max]
            #candidates = overlaps >= modalfractions[i] * bestoverlap
            # maybe just take the top n?
            if len(overlaps) > topn:
                candidates = overlaps.argsort()[-topn:]
            else:
                candidates = range(len(overlaps))
            timetaken = time.time() - lasttime
            lasttime = time.time()
            table[tablerow, 5:] = (len(candidates), bestoverlap, timetaken, bestpose)
            print
            printtable(table, width=9)
            print bestpose
            #scansize = ol.voxels[-1].shape[0]
            poses = poses[candidates]

        print "Total time: ", time.time() - totaltime
        overlaps = overlaps[candidates]
        return bestpose, bestoverlap
        
    def matchbest(self, xyzs, centrepose, spreadpose):
        poses, overlaps = self.match(xyzs, centrepose, spreadpose)
        bestind = np.argmax(overlaps)
        bestpose = poseutil.Pose3D(poses[bestind, :])
        cost = overlaps[bestind]
        return bestpose, cost
    
    def matchandadd(self, ol, centrepose, spreadpose):
        """ matches the given occupiedlist ol by searching around the 
        centrepose a distance of spreadpose. If the match is successful the 
        occupied list is transfomred and combined with the current occupied 
        list. Returns the pose at which the occupied list ol was added."""
        # TODO add a threshold for deciding whether to merge 
        # TODO add unit test for this
        # TODO add a ray trace clear?
        poses, overlaps = self.match(ol, centrepose, spreadpose)
        bestpose = poseutil.Pose3D(poses[np.argmax(overlaps), :])
        self.addpoints(bestpose.transformPoints(ol.getpoints()))
        return bestpose

