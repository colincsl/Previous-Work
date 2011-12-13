cimport cython
import numpy as np
cimport numpy as np

#ctypedef np.float64_t dtype_t
# difference between 32 and 64 bit
ctypedef np.int64_t dtype_i
#ctypedef np.int32_t dtype_i

#cdef dict a
#a = {}
#a['a'] = 1

@cython.boundscheck(False)
def intersection(voxelmap, np.ndarray[dtype_i, ndim=1] voxels):
    cdef Py_ssize_t i, overlap = 0
    for i in range(voxels.shape[0]):
        if voxels[i] in voxelmap:
            overlap += 1
    return overlap

@cython.boundscheck(False)
#@cython.locals(a=cython.double, b=cython.double,
               #N=cython.Py_ssize_t, dx=cython.double,
               #s=cython.double, i=cython.Py_ssize_t)
#@cython.locals(a=cython.double, b=cython.double,
def nested_intersection(dict D, np.ndarray[dtype_i, ndim=2] V):
    cdef Py_ssize_t i, a, b, c, overlap = 0
    for a, b, c in V:
        if a in D and b in D[a] and c in D[a][b]:
            overlap += 1
    return overlap
    
#@cython.boundscheck(False)
#def intersection(voxelmap, np.ndarray[dtype_i, ndim=2] voxels):
#    cdef Py_ssize_t i, overlap = 0
#    for i in range(voxels.shape[0]):
#        if (voxels[i, 0], voxels[i, 1], voxels[i, 2]) in voxelmap:
#            overlap += 1
#    return overlap

@cython.boundscheck(False)
def fillray(dtype_i numcells, np.ndarray[np.float64_t, ndim=1] dir_unit, np.float64_t res, np.ndarray[np.float64_t, ndim=2] ray):
    for i in range(numcells):
        ray[i] = dir_unit*i*res
    return ray
    
@cython.boundscheck(False)
def increment(dict mapvoxels, np.ndarray[dtype_i, ndim=2] voxels, dtype_i amount=1, userdata=None):
    # TODO ensure this remains consistend with the decrement function
    # TODO fails when there is only one voxel
    # TODO add ability to increment according to a vector of occupancies same 
    # length as the array of voxels ie amount should also be allowed to be a 
    # vector of occupancies
    if amount < 0:
        print "Warning: negative increment amount. Consider using decrement() instead."
    cdef np.ndarray[dtype_i, ndim=1] newvoxels = np.zeros(voxels.shape[0], dtype=np.int64)
    cdef dtype_i v0, v1, v2, occupancy
    cdef tuple v
    for i in range(voxels.shape[0]):
        occupancy = 0
        v0 = voxels[i,0]
        v1 = voxels[i,1]
        v2 = voxels[i,2]
        v = (v0, v1, v2) # ensure v is a tuple
        if mapvoxels.has_key(v):
            newvoxels[i] = 0
            occupancy = mapvoxels[v] + amount
        else:
            newvoxels[i] = 1
            occupancy = amount
        if occupancy > 0:
            if userdata == None:
                mapvoxels[v] = occupancy
            else:
                mapvoxels[v] = (occupancy, userdata)
        else:
            del mapvoxels[v]
    return newvoxels.astype(np.bool)

#@cython.boundscheck(False)
#def shmcopy(manager_list):
#    elements = []
#    for el in manager_list:
#        elements.append(el)
#    return elements
