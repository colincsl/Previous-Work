''' Author: Julian Ryde'''
import unittest
import numpy as np
import icp_mrol as icp
import mrol_mapping.poseutil as poseutil
# test procedure, generate points, transform them and check that the algorithm 
# generates the correct transform when given the two sets of points
# could also do region of convergence checks this way
# plotobjective


#P -= np.mean(P, axis=0)
#Q -= np.mean(Q, axis=0)

def generate_data(true_pose, npts=100, pextra=10, qextra=100, noise_bool=True):
    '''Returns map points Q, scan points P and the true pose to move from P to Q (scan to map)'''
    true_pose = np.array(true_pose, dtype=float)

    np.random.seed(6)
    P = 10*np.random.ranf((npts, 3)) # scan points
    noise = 0.05 * np.random.standard_normal(P.shape)
    Q = poseutil.transformPoints(P, poseutil.mat(true_pose))
    # move the map points away from the scan points by pose so that moving the 
    # scan points by pose will match the map
    if noise_bool:
        Q = Q + noise # not sure why we add noise ot the map instead of the scan, but tests fail otherwise?
    # add some points that are unrelated to both P and Q
    X = 10*np.random.ranf((pextra, 3))
    P = np.vstack((P, X))
    X = 10*np.random.ranf((qextra, 3))
    Q = np.vstack((Q, X))
    return P, Q

class TestICP(unittest.TestCase):
    def setUp(self):
        self.guesspose = np.array((1, 0, 0, 1, 0, 0), dtype=float)
        self.true_pose = np.array((1.1, 0, 0, 1.05, 0.01, 0.0), dtype=float)

    def icpalign(self):
        X = icp.align(self.guesspose, self.P, self.Q, terminate_threshold=0.09)[0]
        if debug:
            print 'Expected pose: ', self.true_pose
            print 'Actual pose: ', X
        self.assertTrue(np.allclose(self.true_pose, X, rtol=0.01, atol = 0.05))

    def cost(self, threshold=999999):
        truecost = icp.cost(self.true_pose, self.P, self.Q)
        guesscost = icp.cost(self.guesspose, self.P, self.Q)
        if debug:
            print 'guesscost: ', guesscost
            print 'truecost: ', truecost
        self.assertTrue(truecost < guesscost)

    def test_simple(self):
        self.P, self.Q = generate_data(self.true_pose, pextra=0, noise_bool=False)
        self.icpalign()
        self.cost()

    def test_robust(self):
        self.P, self.Q = generate_data(self.true_pose)
        self.icpalign()
        self.cost()

    def test_cost(self):
        P = np.array( ((0., 0., 0.), (1., 1., 1.)) )
        # TODO cost function fails if there is only one point
        # TODO bug if all all poinst are rejected by threshold
        #self.assertEqual(1, icp.cost((1, 0, 0, 0, 0, 0), P, P), threshold=0.5)

        self.assertAlmostEqual(0.1, icp.cost((0.1, 0, 0, 0, 0, 0), P, P))
        self.P, self.Q = generate_data(self.true_pose, pextra=0, noise_bool=False)
        truecost = icp.cost(self.true_pose, self.P, self.Q)
        self.assertEqual(truecost, 0)

debug = True
if __name__ == '__main__':
    #unittest.main()
    suite = unittest.TestLoader().loadTestsFromTestCase(TestICP)
    unittest.TextTestRunner(verbosity=2).run(suite)
