#!/usr/bin/env python
import numpy as np
import mrol_mapping.poseutil as poseutil
import unittest

class Testposeutil(unittest.TestCase):
    def setUp(self):
        self.p = []
        self.p.append(poseutil.Pose3D())
        self.p.append(poseutil.Pose3D())

    def testtuple_matrix(self):
        X = (0, 0, 0, 0, 0, 0)
        Y =  poseutil.posetuple(poseutil.mat(X))
        self.assertEquals(X, Y)
        X = (0.1, -0.2, 0, 0.45, 0.9, -1.1)
        Y =  poseutil.posetuple(poseutil.mat(X))
        self.assertTrue(np.allclose(X, Y))

    def testeqandhash(self):
        P = self.p
        P = poseutil.Pose3D()
        P.set([1.2, 2.3, 0.2, 0.12, 0.63, 0.9])
        Q = poseutil.Pose3D()
        Q.setMatrix(P.getMatrix())

        self.assertEquals(P, Q)

    def testsetget(self):
        p = self.p
        S = set()
        S.add(p[0])
        S.add(p[1])
        self.assertEquals(len(S), 1)
        S = set()
        p[1].x = 1
        S.add(p[0])
        S.add(p[1])
        self.assertEquals(len(S), 2)
        #self.assertEquals(self.p[0][0], 0)
        #self.assertEquals(self.p[1][5], 1)

    def testcombined(self):
        p = self.p[0]
        combo = p.getCombined(p)
        self.assertTrue(np.allclose(combo.get(), p.get()))
        p.set([1, 1, 0, 0, 0, np.radians(45)])
        combo = p.getCombined(p)
        expected = poseutil.Pose3D()
        expected.set([1, 1+2**0.5, 0, 0, 0, np.radians(90)])
        self.assertTrue(np.allclose(expected.get(), combo.get()))
        # TODO 3D tests still required

    def testtransform(self):
        p = self.p
        p[0].rotz = np.radians(90)
        X = np.matrix('0, 0, 0; 1, 0, 0')
        Y = p[0].transformPoints(X)
        expected = np.matrix('0, 0, 0; 0, 1, 0')
        self.assertTrue(np.allclose(Y, expected)) # pure rotation
        p[1].x = 1
        p[1].y = 2
        p[1].z = 3
        Y = p[1].transformPoints(X)
        expected = np.matrix('1, 2, 3; 2, 2, 3')
        self.assertTrue(np.allclose(Y, expected)) # pure translation
        p[0].x = 1
        Y = p[0].transformPoints(X)
        expected = np.matrix('1, 0, 0; 1, 1, 0')
        # it rotates first then displaces
        self.assertTrue(np.allclose(Y, expected)) # combined

    def testinverse(self):
        p = self.p
        q = p[0].inverse().inverse()
        self.assertEquals(p[0], q)

    def testcopy(self):
        p = self.p
        p[0].x = 1
        p[0].rotx = 2
        c = p[0].copy()
        self.assertFalse(c is p[0])
        self.assertEqual(c, p[0])

if __name__ == '__main__':
    unittest.main()

