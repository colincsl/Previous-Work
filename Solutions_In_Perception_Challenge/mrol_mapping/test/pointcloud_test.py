import unittest
import numpy as np

import mrol_mapping.pointcloud as pointcloud

class TestPointCloud(unittest.TestCase):
    def setUp(self):
        X = np.random.random((10,3))
        self.A = X[:7, :]
        self.B = X[5:, :]
        self.PCA = pointcloud.PointCloud(self.A)
        self.PCB = pointcloud.PointCloud(self.B)
        self.PCC = pointcloud.PointCloud(self.A[:-2])

    def tearDown(self):
        pass

    def test_nearest_neighbour(self):
        NN_dists = pointcloud.nearest_neighbour(self.A, self.B)
        self.assertEqual([5,6], list(np.where(NN_dists < 0.00001)[0]))
        
    def test_equal(self):
        import copy
        self.assertTrue(self.PCA == self.PCA)
        self.assertTrue(self.PCA == copy.deepcopy(self.PCA))
        self.assertFalse(self.PCA == self.PCB)
        self.assertFalse(self.PCA == self.PCC)

if __name__ == '__main__':
    unittest.main()
