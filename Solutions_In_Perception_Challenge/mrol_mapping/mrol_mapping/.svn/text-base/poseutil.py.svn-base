import numpy as np
import quantizer

# TODO replace a transformations  library?
# transformations.py now in lib directory
# This library also has random rotation pose generation 

# TODO make all interfaces consistent and using Pose3D objects

# TODO need to test mat and posetuple functions properly rather than just testing that 
# they invert one another

def mat(pose):
    '''Convert pose tuple in form x, y, z, rotx, roty, rotz to matrix'''
    #M = transformations.euler_matrix(pose[3], pose[4], pose[5], 'sxyz')
    #M[:3, 3] = pose[:3]
    P = Pose3D(pose)
    return P.getMatrix()

def posetuple(posemat):
    '''Convert pose matrix 4x4 to pose tuple x, y, z, rotx, roty, rotz'''
    P = Pose3D()
    P.setMatrix(posemat)
    return P.get()
    
# TODO combine tuplepose and posetuple into one function
def tuplepose(pose):
    '''Convert an array like 6 element pose representation to a tuple x, y, z, rotx, roty, rotz'''
    return (pose[0], pose[1], pose[2], pose[3], pose[4], pose[5])
    
# TODO enable transformPoints function to take either matrix or pose tuple, and modify 
# where this function is invoked accordingly
def transformPoints(xyz, posemat):
    '''returns the transform of a list of points n by 3 by applying the 
    matrix transform described by mat'''
    # TODO probably would be faster to transform in place
    #M = np.vstack((xyz[:, 0:3].T, np.ones((1, xyz.shape[0]))))
    #return np.dot(mat, M).T[:, 0:3]
    # below is faster?
    rotated = np.dot(posemat[:3, :3], xyz.T).T
    rotated += posemat[:3, 3] 
    return rotated
    
# TODO combine transformPointsTuple into transformPoints
def transformPointsTuple(xyz, pose_tuple):
    pose_mat = mat(pose_tuple)
    return transformPoints(xyz, pose_mat)

def refineposes(poses, deltaposition, deltaorientation):
    '''Produces a new set of poses that are around the supplied poses'''
    # TODO this needs to be done properly for 3D
    # TODO does not handle a single pose
   
    # each pose should spawn 3 new poses for each dimension
    # this definitely produces better results in 2D tested by testing on 2D mapping 
    # and looking at the voxel count of the final map
    #mg = np.mgrid[-1:2, -1:2, -1:2, -1:2, -1:2, -1:2].astype(float)
    # each pose should spawn 2 new poses for each dimension

    mg = np.mgrid[-1:1, -1:1, -1:1, -1:1, -1:1, -1:1].astype(float)
    mg += 0.5

    mg.shape = 6, -1
    mg = mg.T

    # TODO remove this nasty hack for 3DOF speed
    #mg[:, [2, 3, 4]] = 0
    #mg = quantizer.uniquerows(mg, 3)

    mg[:, 0:3] *= deltaposition
    mg[:, 3:6] *= deltaorientation
    #zerorows = np.zeros((6, mg.shape[1]))
    #mg = np.vstack((mg[0:3, :]*deltaposition, zerorows, mg[3:6, :]*deltaorientation))

    refinedposes = np.empty((poses.shape[0]*mg.shape[0], 6))
    row = 0
    for p in poses:
        ptile = np.tile(p, (mg.shape[0], 1))
        newposes = ptile + mg
        refinedposes[row:row+mg.shape[0], :] = newposes
        row += mg.shape[0]

    # TODO remove those outside of centrepose + spreadpose
    return quantizer.uniquerows(refinedposes, 3)

def uniformposes(centrepose, spreadpose, positionres, orientationres):
    """ Produce uniform distribution of poses with positions separated by 
    positionres and orientations separated by orientationres, centered around 
    center pose and spanning +/- spreadpose """
    # TODO this needs to be done properly for 3D poses
    # see papers on generating uniform random 3D rotations
    cp = np.array(centrepose.get())
    sp = np.array(spreadpose.get())
    B = cp - sp 
    E = cp + sp + 0.0001 
    # this small addition is to fix when the spreadpose is 0 still want to 
    # generate some poses rather than none
    S = np.hstack((np.tile(positionres, 3), np.tile(orientationres, 3)))
    pose_count = np.prod((E-B)/S)
    assert pose_count < 1e5, 'Requested too many poses %d' % int(pose_count)

    mg = np.mgrid[B[0]:E[0]:S[0], B[1]:E[1]:S[1], B[2]:E[2]:S[2], B[3]:E[3]:S[3], B[4]:E[4]:S[4], B[5]:E[5]:S[5]]
    mg.shape = 6, -1
    return quantizer.uniquerows(mg.T, 3)
    
def randomrot():
    """ Return an uniformly distributed random rotation matrix """
    # TODO write a test for this somehow. NFI.
    # make a random quaternion 
    randelements = np.random.rand(3)
    lin1 = np.sqrt(1.0 - randelements[0])
    lin2 = np.sqrt(randelements[0])
    rot1 = 2*np.pi * randelements[1]
    rot2 = 2*np.pi * randelements[2]
    x = np.sin(rot1)*lin1
    y = np.cos(rot1)*lin1
    z = np.sin(rot2)*lin2
    w = np.cos(rot2)*lin2
    quat = np.array([x,y,z,w])
    quat *= np.sqrt(2.0/np.dot(quat,quat)) # not sure if we need this line
    q = np.outer(quat,quat) # assumes quat is properly normalised... hrmm
    mat = np.array([[1.0-q[1, 1]-q[2, 2],     q[0, 1]-q[2, 3],              q[0, 2]+q[1, 3]], 
                    [    q[0, 1]+q[2, 3],     1.0-q[0, 0]-q[2, 2],          q[1, 2]-q[0, 3]], 
                    [    q[0, 2]-q[1, 3],         q[1, 2]+q[0, 3],      1.0-q[0, 0]-q[1, 1]]])
    return mat
    
    

# TODO allow pose_str function to also take in a pose in matrix form
def pose_str(P):
    '''Convert 6 element pose x, y, z, rotx, roty, rotz to a string with angles 
    in degrees'''
    pose = Pose3D(P)
    return str(pose)
    
def check_and_transform_points(xyzs,pose):
    '''Check the type of pose passed and perform the transformation'''
    if type(pose) == type(Pose3D()):
        if pose == Pose3D():
            xyzs = xyzs # do nothing
        else:
            xyzs = transformPoints(xyzs, pose.getMatrix())   
        pose_return = pose
    else:
        if pose == None or (np.array(pose) == np.array((0, 0, 0, 0, 0, 0))).all() or (np.array(pose) == np.array((0.0, 0.0, 0.0, 0.0, 0.0, 0.0))).all():
            xyzs = xyzs # do nothing
            pose_return = Pose3D()
        else:
            xyzs = transformPointsTuple(xyzs, pose)
            pose_return = Pose3D(pose)
    return xyzs, pose_return
    
def inverse(pose):
    '''compute the inverse transform of that given'''
    posemat = mat(pose)
    invPose = np.matrix(posemat).I
    return posetuple(invPose)
    
# TODO use an array to store pose rather than self.x, self.y, ...
class Pose3D:
    """ 3D pose """
    def __init__(self, X=(0, 0, 0, 0, 0, 0)):
        """ Initialises a pose with no translation and no rotation """
        #if type(posestr) == str:
        #    fields = posestr.split()
        #else:
        #    fields = posestr
        
        # TODO Something like below so we can assign from one Pose3D to another
        #if type(X) == type(Pose3D()):
        #    X = X.getTuple()
        
        self.set(X)
        self.tol = 6 # number of decimals places to round to

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        return '%.4f %.4f %.4f %.4f %.4f %.4f' % (self.x, self.y, self.z, np.degrees(self.rotx), np.degrees(self.roty), np.degrees(self.rotz))

    # __eq__ and __hash__ must be consistent
    # TODO fix to handle equal tolerance maybe with rounding
    def __eq__(self, o):
        if o == None:
            return False
        return np.allclose(self.get(), o.get(), atol=0.0001)
    
    def __hash__(self):
        X = np.around(self.get(), self.tol)
        return hash(tuple(X))

    def is_close(self, o, delta_pos, delta_angle_rad):
        '''Returns true if the pose is within delta_pos position and 
        delta_angle orientation, delta_angle is in radians'''
        # TODO will be better when the pose components are stored as a numpy 
        # array internally 
        if abs(self.x - o.x) > delta_pos: return False
        if abs(self.y - o.y) > delta_pos: return False
        if abs(self.z - o.z) > delta_pos: return False
        if abs(self.rotx - o.rotx) > delta_angle_rad: return False
        if abs(self.roty - o.roty) > delta_angle_rad: return False
        if abs(self.rotz - o.rotz) > delta_angle_rad: return False
        return True

    def copy(self):
        c = Pose3D()
        c.setMatrix(self.getMatrix())
        return c

    def inverse(self):
        """ returns a pose which is the inverse of this pose 
        """
        M = np.linalg.inv(self.getMatrix())
        p = Pose3D()
        p.setMatrix(M)
        return p

    def set(self, X):
        X = np.ravel(X) # handle lists, tuples and 6x1 and 1x6 arrays
        self.x = float(X[0])
        self.y = float(X[1])
        self.z = float(X[2])
        self.rotx = float(X[3])
        self.roty = float(X[4])
        self.rotz = float(X[5])

    def get(self):
        return (self.x, self.y, self.z, self.rotx, self.roty, self.rotz)

    # TODO refactor these identical functions together?
    def getTuple(self):
        return (self.x, self.y, self.z, self.rotx, self.roty, self.rotz)

    def getMatrix(self):
        """ returns 4x4 matrix representing this pose """
        sq = np.sin(self.rotx)
        cq = np.cos(self.rotx)
        Rx = [[1, 0, 0], [0, cq, -sq], [0, sq, cq]]
        sq = np.sin(self.roty)
        cq = np.cos(self.roty)
        Ry = [[cq, 0, sq], [0, 1, 0], [-sq, 0, cq]]
        sq = np.sin(self.rotz)
        cq = np.cos(self.rotz)
        Rz = [[cq, -sq, 0], [sq, cq, 0], [0, 0, 1]]
        # this order is important
        #R = np.dot(Rx, np.dot(Ry, Rz))
        R = np.dot(Rz, np.dot(Ry, Rx))
        T = [[self.x], [self.y], [self.z]]
        trans = np.hstack((R, T))
        trans = np.vstack([trans, [0, 0, 0, 1]])
        return trans.astype(np.single)

    def setMatrix(self, mat):
        """ sets the pose according to the 4x4 transform matrix """
        self.rotx = np.arctan2(mat[2, 1], mat[2, 2]);
        self.roty = np.arcsin(-mat[2, 0]);
        self.rotz = np.arctan2(mat[1, 0], mat[0, 0]);
        self.x = mat[0, 3]
        self.y = mat[1, 3]
        self.z = mat[2, 3]

    def getCombined(self, p):
        A = self.getMatrix()
        B = p.getMatrix()
        C = Pose3D()
        C.setMatrix(np.dot(A, B))
        return C

    def transformPoints(self, xyz):
        """ returns a transform of a list of points n by 3 by applying the 
        matrix transform described by this pose """
        return transformPoints(xyz, self.getMatrix())
        
    def inverse(self):
        return Pose3D(inverse(self.getTuple()))
        
def axis_order(horz_rot, vert_rot, axis):
    assert axis in [0,1,2], "axis must be 0, 1 or 2 (x, y or z)"
    if axis == 2:
        return ([horz_rot, vert_rot, 0])
    elif axis == 1:
        return ([horz_rot, 0, vert_rot])
    elif axis == 0:    
        return ([0, horz_rot, vert_rot])
        
def scan_pose_list(FOVV, resV, FOVH, resH, axis=0):
    ''' Create a list of poses that cover the angular region defined by 
    the input arguments, about the defined axis'''
    assert axis in [0,1,2], "axis must be 0, 1 or 2 (x, y or z)"
    print "scan poses based on:"
    print FOVV, resV, FOVH, resH
    assert np.remainder(np.round(FOVV/resV),2) == 0, "FOVV/resV must be an even integer"
    assert np.remainder(np.round(FOVH/resH),2) == 0, "FOVH/resH must be an even integer"
    numV = 2*np.ceil(FOVV/resV/2)+1
    numH = 2*np.ceil(FOVH/resH/2)+1
    # must be odd so we have a definitive center pixel
    if np.remainder(numV,2) != 1:
        numV = numV + 1
    if np.remainder(numV,2) != 1:
        numV = numV + 1
    numposes = numV*numH
    center = np.floor(numposes/2)
    poses_ang = np.zeros((numposes,3))
    poses_lin = np.zeros((numposes,3))
    # top left
    count = 0
    for i in np.arange(-FOVH/2,0,resH):
        horz_rot = i
        for j in np.arange(0,FOVV/2+resV,resV):
            vert_rot = j
            poses_ang[count,:] = axis_order(horz_rot, vert_rot, axis)
            count = count + 1
        vert_rot = 0
    # top right, center pixel
    for i in np.arange(0,FOVH/2+resH,resH):
        horz_rot = i
        for j in np.arange(0,FOVV/2+resV,resV):
            vert_rot = j
            poses_ang[count,:] = axis_order(horz_rot, vert_rot, axis)
            count = count + 1
        vert_rot = 0
    # bottom left
    for i in np.arange(-FOVH/2,0,resH):
        horz_rot = i
        for j in np.arange(-FOVV/2,0,resV):
            vert_rot = j
            poses_ang[count,:] = axis_order(horz_rot, vert_rot, axis)
            count = count + 1
        vert_rot = 0
    # bottom right
    for i in np.arange(0,FOVH/2+resH,resH):
        horz_rot = i
        for j in np.arange(-FOVV/2,0,resV):
            vert_rot = j
            poses_ang[count,:] = axis_order(horz_rot, vert_rot, axis)
            count = count + 1
        vert_rot = 0
    poses = np.hstack([poses_lin,poses_ang])
    return poses
