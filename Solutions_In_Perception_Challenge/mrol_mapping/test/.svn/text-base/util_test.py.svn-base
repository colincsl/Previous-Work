import numpy as np
import mrol_mapping.util as util
import unittest
import mrol_mapping.pointcloud as pointcloud

class test_util(unittest.TestCase):
    def setUp(self):
        self.pc = pointcloud.PointCloud((
                (0, 0, 0),
                (0.1, 0.1, 0.1),
                (1, 1, 1),
                (1, 1, 1.01),
                ))

        self.res = 0.2

    def test_boxfilter(self):
        X = np.zeros((3,3))
        util.boxfilter(X, (0,0,0), (0,0,0))
        X = np.zeros((1,3))
        util.boxfilter(X, (0,0,0), (0,0,0))
        X = (0,0,0)
        util.boxfilter(X, (0,0,0), (0,0,0))
        X = np.zeros((0,3))
        util.boxfilter(X, (0,0,0), (0,0,0))

    def test_volumetricsample(self):
        sample = util.volumetricsample(self.pc.points, self.res) 
        self.assertEqual(len(sample), 2)
        #xyzs = np.arange(1500).reshape(500, 3)
        #xyzs = np.random.randint(50,size=(1500,3))
        #xyzs = xyzs*0.01
        xyzs = np.random.randn(1500,3)
        import mrol_mapping.occupiedlist as occupiedlist
        ol = occupiedlist.OccupiedList(0.1)
        ol.addpoints(util.volumetricsample(xyzs,0.1))
        inpts, outpts = ol.segment_ovl(None,xyzs)
        self.assertTrue(len(outpts) == 0)

if __name__ == '__main__':
    unittest.main()
