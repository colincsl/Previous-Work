from __future__ import division
import numpy as np
import poseutil

def cost_min(cost_func, initialpose, args, dx, dq, max_iterations=100, verbosity=0, two_D=False):
    if isinstance(initialpose, poseutil.Pose3D):
        bestpose = np.asarray(initialpose.getTuple())
    else:
        bestpose = np.asarray(initialpose)
    already_checked = {}
    # TODO use manhatten moves so no diagonal moves, can still move 
    # diagonally but takes two steps however drastically cuts number of 
    # adjacent poses to test from 2^6 to 2*6
    # each coord is plus or minus 1 individually all other are held the same
    # this is equivalent to partial differentiation and should only need 12 
    # poses to check
    X = np.array([1,0,0])
    Y = np.array([0,1,0])
    Z = np.array([0,0,1])
    if two_D:
        raise NotImplmented
        # TODO fix this as per below
        #mg = np.vstack((
        #(1.  , 0   , 0 , 0 , 0 , 0)   , 
        #(0   , 1.  , 0 , 0 , 0 , 0)   , 
        #(0   , 0   , 0 , 0 , 0 , 1.)  , 
        #(-1. , 0   , 0 , 0 , 0 , 0)   , 
        #(0   , -1. , 0 , 0 , 0 , 0)   , 
        #(0   , 0   , 0 , 0 , 0 , -1.) , 
        #))
    else:
        # TODO Try parallel testing of these poses.
        #import pydb;pydb.set_trace()
        mg = np.vstack((np.identity(6), -np.identity(6)))
        x_ = np.hstack([np.vstack([X,X,X]),np.identity(3)])
        x__ = np.hstack([np.vstack([X,X,X]),-np.identity(3)])
        y_ = np.hstack([np.vstack([Y,Y,Y]),np.identity(3)])
        y__ = np.hstack([np.vstack([Y,Y,Y]),-np.identity(3)])
        z_ = np.hstack([np.vstack([Z,Z,Z]),np.identity(3)])
        z__ = np.hstack([np.vstack([Z,Z,Z]),-np.identity(3)])
        mg = np.vstack([mg,x_,-x_,x__,-x__,y_,-y_,y__,-y__,z_,-z_,z__,-z__])
        
    mg[:, 0:3] *= dx
    mg[:, 3:6] *= dq    
    initialoverlap = -cost_func(bestpose, args[0])
    previousmax = initialoverlap
    maxo = initialoverlap
    p_tup = poseutil.tuplepose(bestpose)
    already_checked[p_tup] = True
    called_count = 1
    iter_count = 0
    if verbosity > 1:
        print 'Scan voxel count, overlaps, max overlap'
    for i in range(max_iterations):
        iter_count += 1
        poses = bestpose + mg
        overlaps = []
        # check poses surrounding bestpose
        for p in poses:
            p_tup = poseutil.tuplepose(p)
            # optimization to save calculating the cost for poses which we have 
            # previously calculated the cost for
            if already_checked.has_key(p_tup):
                overlaps.append(0)
                continue
            else:
                already_checked[p_tup] = True
                cost = -cost_func(p, args[0])
                # negative because this is a maximiser
                called_count += 1
                overlaps.append(cost)
                if verbosity > 3:
                    print poseutil.Pose3D(p), cost
        assert len(overlaps) != 0, "Already checked ALL of these poses: Some sort of circular minimisation error?"
        overlaps = np.array(overlaps)
        maxoi = np.argmax(overlaps)
        maxo = overlaps[maxoi]
        if sum(overlaps == maxo) > 1:
            print 'WARNING: multiple maxima'
        if verbosity > 2:
            print i, ':', overlaps, maxo
            #print 'Best pose:', poses[maxoi]
        # break if current pose is maximum in the case when alternative pose is 
        # of equal overlap pick the previous pose
        if maxo <= previousmax: 
            maxo = previousmax
            break
        else:
            # re-assign for next loop
            bestpose = poses[maxoi]
            previousmax = maxo
        if verbosity > 1:
            print bestpose, maxo
    if iter_count >= max_iterations:
        print "WARNING: Maximum number of iterations reached. Solution did not reach convergence."
    
    if verbosity > 0:
        print 'cost function evaluated:', called_count, 'times over', iter_count, 'iterations'
        print len(args[0]), 'cost increase:', initialoverlap, '->', maxo
    return bestpose, -maxo # -ve again because it is standard for the calling function to assume a minimisation.
 
   
def plotobjective(cost_func, initialpose, xyzs, plot_range=(-0.2, 0.2, np.radians(-5), np.radians(5)), dx=None, dq=None):
    '''
    Plots the cost function for various poses, centered about the initialpose.
    '''
    dofs = {0:'x', 1:'y', 2:'z', 3:'rotx', 4:'roty', 5:'rotz'}
    xmin, xmax = plot_range[:2]
    qmin, qmax = plot_range[2:]
    if dx == None:
        dx = (xmax-xmin)/100.0
    if dq == None:
        dq = (qmax-qmin)/100.0
    ranges = np.array([
           [xmin, xmin, xmin, qmin, qmin, qmin],
           [xmax, xmax, xmax, qmax, qmax, qmax],
           [dx, dx, dx, dq, dq, dq]])
    ranges = ranges.T
    import pylab
    pylab.ion()
    pylab.figure()
    pylab.subplot(2, 1, 1)
    for i in range(3):
        X = np.arange(ranges[i, 0], ranges[i, 1], ranges[i, 2]) + initialpose[i]
        pose = np.array(initialpose, dtype=float)
        Y = []
        for x in X:
            pose[i] = x
            Y.append(cost_func(pose, xyzs))
        pylab.plot(X - initialpose[i], Y, 'x-', label=str(dofs[i]))
        print "+"
    pylab.legend()
    pylab.xlabel('m')
    pylab.ylabel('objective function value')
    pylab.subplot(2, 1, 2)
    for i in range(3, 6):
        X = np.arange(ranges[i, 0], ranges[i, 1], ranges[i, 2]) + initialpose[i]
        pose = np.array(initialpose, dtype=float)
        Y = []
        for x in X:
            pose[i] = x
            Y.append(cost_func(pose, xyzs))
        pylab.plot(X - initialpose[i], Y, 'x-', label=str(dofs[i]))
        print "*"
    pylab.legend()
    pylab.xlabel('rad')
    pylab.ylabel('objective function value')
    #pylab.show()
    #pylab.draw()



