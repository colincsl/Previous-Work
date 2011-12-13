'''Trajectory class

Author: Nick Hillier'''

### FUNCTIONS BELOW THIS LINE NEED DEVELOPMENT AND/OR REFACTORING INTO DIFFERENT CLASSES. THEY MAY NOT HAVE ADEQUATE TEST COVERAGE! ###
        
class Trajectory:        
    # TODO integrate the trajectory information into the actual map, via timestamping and modification to add_points/remove_points
    # TODO consider removing the trajectory information or storing as a tree - perhaps this Mapper should only contain points pre-SLAMed?
    # maintain a trajectory of poses and pointclouds for loop closure if desired
    self.trajectory = {} # members are pose, pointcloud, overlap between this and previous pointcloud.
    #self.trajectory_times = {} # members are timestamp and pose, to index into self.trajectory
    self.trajectory_times = []

    # TODO come up with a better name for the align_add_points_loops function
    #def align_add_points_loops(self, xyzs, guess_pose, timestamp):
    #    if len(self.mrol.getkeyframe()) == 0:
    #        self.mrol.setkeyframe(xyzs,guess_pose)
    #    bestpose, maxo, added = align_add_points(self, xyzs, guess_pose, timestamp=timestamp, add_ratio=0.5) # we can have a lower overlap because we can re-process when we find a loop.
    #    if self.getoverlap(guess_pose, xyzs, keyframe=True)/len(xyzs) < 0.5:
    #        self.mrol.setkeyframe(xyzs,guess_pose)
    #        # do place recognition of xyzs against mrol map to try to 
    #        # find a loop closure. 
    #        # TODO Julian insert function call here
    #        
    #        # do loop relaxation if place recognition probability is high
    #        if recog_prob > 0.8: # TODO Julian pick a magic number here
    #            relaxposes = self.mrol.calc_loop_relax_poses(self, timestamp_current, timestamp_closest_desired, pose_desired, inv_wt=100.)
    #            self.mrol.journal(timestamp_closest_desired, timestamp_current, relaxposes)

    #def align_points_to_traj(self, timestamp, xyzs, guess_pose=None, quiet=True, levels=1, two_D=False):
    #    traj_ts, key_pose = self.get_latest_traj_ts(timestamp)
    #    if guess_pose == None:
    #        guess_pose = key_pose
    #    assert traj_ts > 0, "no valid trajectory timestamps to align against"
    #    traj_points = self.trajectory[key_pose][0]
    #    traj_points = poseutil.transformPointsTuple(traj_points,key_pose)
    #    for lev in range(levels)[::-1]:
    #        resolution = pow(2,lev)*self.res
    #        if self.verbose > 1:
    #            print lev, self.res, resolution
    #        voxel_array = occupiedlist.pointstovoxels(traj_points, resolution, unique=True) # does the volumetric sampling for us?
    #        voxel_set = set(occupiedlist.hashrows(voxel_array)) 
    #        self._traj_alignment_voxel_set = voxel_set
    #        returns = optimization.gauss_siedel(self._trajectory_objective, guess_pose, args=(xyzs,1.), dx = resolution, dq=(resolution/self.feature_range), quiet=quiet, two_D=two_D)
    #        #returns = opt.fmin_powell(self._trajectory_objective, guess_pose, args=(xyzs, 1.), disp=False, full_output=True)
    #        guess_pose = returns[0]
    #        cost = returns[1]
    #    bestpose = guess_pose
    #    return bestpose, cost
    
    #def add_to_trajectory(self, timestamp, pose, xyzs, cost):
    #    pose_r = []
    #    for pval in pose:
    #        pose_r.append(round(pval,5))
    #    pose_tup = poseutil.tuplepose(pose_r)
    #    self.trajectory[pose_tup] = (xyzs,cost)
    #    self.trajectory_times.append((timestamp, pose_tup))
    #    
    #def get_latest_traj_ts(self, timestamp=None):
    #    closest_diff = 999.
    #    traj_ts = -1.
    #    traj_pose = [0,0,0,0,0,0]
    #    if timestamp == None:
    #        for ts in self.trajectory_times:
    #            if ts[0] > traj_ts:
    #                traj_ts = ts[0]
    #                traj_pose = ts[1]
    #    else:
    #        for ts in self.trajectory_times:
    #            if ts[0] > timestamp:
    #                continue
    #            diff = timestamp - ts[0]
    #            if (diff < closest_diff) and (ts[0] <= timestamp):
    #                closest_diff = diff
    #                traj_ts = ts[0]
    #                traj_pose = ts[1]
    #    return traj_ts, traj_pose
    #    
    ##def save_trajectory(self, filename_base):
    #    
    #
    #def relax_loop(self, timestamp_current, timestamp_closest_desired, pose_desired, inv_wt=100.):
    #    '''
    #    NOTE: This is an overly simple loop relaxation schema for single-loop trajectories with no intra-loop overlap. Loop relaxation with more complicated 
    #    trajectories requires a more comprehensive representation (e.g. a proper node graph). If loop relaxation is required for such scenarios, it is recommended 
    #    that something like TORO (http://www.openslam.org/toro.html)
    #    
    #    Want to relax loop between existing self.trajectory entry at timestamp_current and pose_desired (i.e. want the self.trajectory pose to equal pose_desired)
    #    timestamp_closest_desired is the timestamp of the self.trajectory entry closest to the desired pose and determines the start of the loop for relaxation.
    #    If the loop has returned to exactly the same place as the pose at timestamp_closest_desired, then pose_desired = self.get_latest_traj_ts(ts0)[1]
    #    
    #    The algorithm uses the overlap (or whatever other cost metric is defined) values in self.trajectory as proportional to inverse of weightings that determine
    #    the flexibility of the connection. This assumes that a higher cost self.trajectory = more certain alignment in a linear manner. Good performance has been 
    #    observed when using the cost = overlap/len(XYZsamples) (remember to use floating point division!)
    #    
    #    The inv_wt argument is to reduce errors due to numerical imprecision, if the sum of the costs for the loop is big, then inv_wt may need to be increased. 
    #    The value of inv_wt has no effect on the algorithm performance other than scaling for numerical imprecision and could just as well be unitary.
    #    
    #    Compute pose error
    #    The algorithm will try to make pose_err = zero  
    #    '''
    #    pose_ts = np.array(self.get_latest_traj_ts(timestamp_current)[1])
    #    pose_err = pose_ts - pose_desired
    #    for i in range(3,6):  #TODO: better handling of angular errors, not convinced that this is correct.
    #        pose_err[i] = np.unwrap([pose_desired[i],pose_ts[i]])[1]  # clamp angular errors 
    #    if self.verbose > 0:
    #        print "Loop relaxation initial pose error:", pose_err
    #    #
    #    # First implementation, simply: compute difference between pose_traj and pose_desired in 6DOF and split 
    #    # it amongst the self.trajectory poses according to the weightings.
    #    #
    #    # A second implementation could use the first implementation's result as the seed poses and re-run the optimization process over
    #    # all trajectory elements in a single large optimization. This should be a constrained optimization procedure, with the start and
    #    # end loop poses fixed, and the objective function being the sum of the cost functions for all individual trajectory elements.
    #    #
    #    inv_costs = []
    #    ts_start = self.get_latest_traj_ts(timestamp_closest_desired)[0]
    #    traj_times_copy = []
    #    count = -1 # increments to zero on loop entry
    #    for traj_inds in self.trajectory_times:
    #        count = count + 1
    #        if traj_inds[0] <= ts_start:
    #            continue
    #        if traj_inds[0] > timestamp_current:
    #            break
    #        traj_times_copy.append((traj_inds,count))
    #        inv_costs.append(inv_wt/self.trajectory[traj_inds[1]][1])
    #    sum_inv_cost  = np.sum(inv_costs)
    #    unit_pose_peturb = -pose_err/sum_inv_cost # -ve because we want to remove the error
    #    # loop relaxation DOES need to be done in chronological order
    #    pose_corr = np.array([0,0,0,0,0,0])
    #    for traj_inds in traj_times_copy:
    #        old_pose = traj_inds[0][1]
    #        pose_corr = pose_corr + inv_wt/self.trajectory[traj_inds[0][1]][1]*unit_pose_peturb
    #        new_pose = old_pose + pose_corr
    #        pose_tup = poseutil.tuplepose(new_pose)
    #        # overwrite the content of self.trajectory and selt.trajectory_times with the corrected poses
    #        self.trajectory_times[traj_inds[1]] = (traj_inds[0][0], pose_tup)
    #        self.trajectory[pose_tup] = self.trajectory.pop(old_pose) # we are keeping the old cost here for lack of a better one.
