from __future__ import division

import numpy as np

def __calcfx(X):
    # this not quite correct as for 0.5 should actually round down
    # ie choose integer with smallest absolute value
    return np.round(X)

# helper function that returns f(x) and g(x) as a tuple
def __calcfxgx(X):
    fx = __calcfx(X) 
    # g(x) is same as f(x) but with worst component of x i.e. one with 
    # largest quantisation error is rounded the wrong way
    # if two are equally bad then lowest subscript is taken
    # wi is the index of the worst one
    gx = np.copy(fx)
    D = X - fx
    W = np.max(np.abs(D), 1) 
    
    mask = np.abs(D) == np.tile(W, (3, 1)).T
    # for this worst index one need to go to the nearest integer in the 
    # opposite direction to the original rounding operation
    # such that f(x) and g(x) should contain x 
    roundedup = X < fx # been rounded up
    gx[np.logical_and(roundedup, mask)] -= 1
    gx[np.logical_and(np.logical_not(roundedup), mask)] += 1
    return fx, gx

def tidy(X, resolution=None): 
    # makes X a consistent format for processing
    if type(X) != np.ndarray:
        X = np.array(X)
    if X.ndim == 1:
        X.shape=1, 3
    if resolution == None:
        return X
    return X/resolution

def uniquerows(X, decimalplaces, return_frequencies=False):
    """ Returns array consisting of unique rows and a list of the number of 
    times each row appeared.  Uniqueness is subject to rounding to the 
    specified number of decimal places. """
    # TODO there could be a serious bug with hash collisions in this implementation
    # TODO update this function to use the integer packing as a hash function?
    if len(X.shape) == 1:
        return np.unique1d(X)
    hashvec = np.random.random(X.shape[1])
    rowhashes = np.dot(np.around(X, decimalplaces), hashvec)
    # only appears to be consistent up to 12 decimal places
    rowhashes = np.around(rowhashes, 12)

    #rowhashes.sort()
    uniqs, inds = np.unique1d(rowhashes, return_index=True)
    # return_index of unique1d does not always return the first one

    # TODO faster way of doing this??
    # maybe something like diff(where(diff(sort(rowhashes))))
    # slow but simple way iterating through all rows
    if return_frequencies:
        ol = dict()
        for i in rowhashes:
            if ol.has_key(i):
                ol[i] += 1 
            else:
                ol[i] = 1
        return X[inds, :], ol.values()
    else: 
        return X[inds, :]

# TODO enable the quantizer functions to accept cell volume rather than resolution?
# converts an xyz value to its voxel
def quantize_cubic(X, resolution):
    X = tidy(X, resolution)
    N = np.round(X).astype(int)
    return N

# fcc lattice, Dn
def quantize_fcc(X, resolution):
    X = tidy(X, resolution)
    (fx, gx) = __calcfxgx(X)
    # pick the ones with an even indices sum
    gxevens = np.sum(gx, 1) % 2 == 0
    fx[gxevens, :] = gx[gxevens, :]
    return fx

# bcc lattice, D3*
def quantize_bcc(X, resolution):
    X = tidy(X, resolution)
    # bcc D3* is union of two cosets with r0 = (0, 0, 0)
    # and r1 = (0.5, 0.5, 0.5)
    r1 = np.tile(0.5, X.shape)
    y0 = __calcfx(X)
    y1 = __calcfx(X-r1) + r1
    # return whichever of y0 or y1 is closest to X
    y0dist = np.sum((X-y0)**2, 1)
    y1dist = np.sum((X-y1)**2, 1)

    changes = y0dist>y1dist
    y0[changes, :] = y1[changes, :]
    #return y0*resolution
    y0 *= 2 # make it integers for set operations
    return 0.5*y0

lattice_funcs = {'cubic':quantize_cubic, 'fcc':quantize_fcc, 'bcc':quantize_bcc}
    
def quantize_hex(X, resolution):
    # expects 2D points and quantises to hexagonal lattice
    D = np.array([3*resolution, np.sqrt(3)*resolution])

    L1 = np.round(X/D)*D
    L2 = (np.floor(X/D)+0.5)*D
    L1nearer = np.sum((X-L1)**2, 1) < np.sum((X-L2)**2, 1)
    L2[L1nearer, :] = L1[L1nearer, :]
    return L2

def estimateVoxelVolume(latticetype, samples=1000, res=1):
    """ estimate volume of one cell of each quantisation uniform distribution 
    of points throughout volume """
    # determine a particular voxel index vi by quantising the origin
    vi = [0, 0, 0]
    width = res
    # generate random points around that vi
    M = np.random.uniform(-width, width, (samples, 3))
    func = lattice_funcs[latticetype]
    N = func(M, res)
    mask = np.all(N == vi, 1)
    #if sum(mask) == 0:
        #mask = np.all(N == [1, 2, 1], 1)

    vol = width**3 * sum(mask)/samples
    # TODO showpts has been refactored out to somewhere else 
    M = M[mask, :]
    return vol
