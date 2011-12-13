#!/usr/bin/env python

import unittest
import numpy as np

import mrol_mapping.quantizer as quantizer

class TestQuantizer(unittest.TestCase):
    def setUp(self):
        self.resolution = 1

    def isequal(self, expected, actual):
        #tests whether two arrays are equal within tolerance
        #print '\nExpected:\t', expected 
        #print 'Actual:\t\t' , actual
        self.assertTrue(np.allclose(expected, actual))

    def testuniquerows(self):
        #self.X[5, :] = [0, 1, 2]
        rows = 10
        X = np.random.random((rows, 3))
        X = np.tile(X, (3, 1))
        np.random.shuffle(X)
        UR, freqs = quantizer.uniquerows(X, 3, return_frequencies=True)
        self.assertEquals(len(UR), rows)
        self.isequal(np.tile(3, 10), freqs)
        # TODO occupances currently do not correspond to rows?
        # test this

        # repeat to make sure nothing changes 
        UR = quantizer.uniquerows(UR, 3)
        self.assertEquals(len(UR), rows)

    def testquantize_fcc(self):
        xyz = np.array([[0.6, -1.1, 1.7, 0.1], [0.6, -1.1, 1.7, 0.1]]);
        actual = quantizer.quantize_fcc(xyz, self.resolution);
        expected = np.array([[1, -1, 2, 0]]);
        self.isequal(expected, actual)

    def testquantize_bcc(self):
        xyz = np.array([[0.2, 0.5, 0.8], [0.2, 0.5, 0.8]])
        actual = quantizer.quantize_bcc(xyz, self.resolution);
        expected = np.array([[0.5, 0.5, 0.5]]);
        self.isequal(expected, actual)

    def testquantizecube(self):
        expected = [1, 2, 3]
        actual = quantizer.quantize_cubic([[1.1, 2.2, 3.3]], self.resolution)
        self.isequal(expected, actual)

    def testsinglepoint(self):
        # test all quantizers on a single point as a list
        quantizers = [quantizer.quantize_cubic, quantizer.quantize_bcc, quantizer.quantize_fcc]
        for q in quantizers:
            q([1, 1, 1], self.resolution)

    def testestimateVoxelVolume(self):
        expectedvols = [1, 0.5, 2]
        # expected ratio 1:1/2:2
        # test with res other than 1
        for res in (1, 0.5, 0.1, 5):
            vols = []
            for latticetype in ('cubic', 'bcc', 'fcc'):
                vols.append(quantizer.estimateVoxelVolume(latticetype, 10000, res=res))

            vols = np.array(vols)/vols[0]
            error = np.sum(np.absolute(vols - expectedvols))
            self.assertTrue(error < 0.15)

if __name__ == '__main__':
    unittest.main()
    #suite = unittest.TestLoader().loadTestsFromTestCase(TestOccupiedList)
    #unittest.TextTestRunner(verbosity=2).run(suite)
