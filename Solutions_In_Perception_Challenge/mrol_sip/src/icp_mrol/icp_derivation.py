from sympy import *
# rotx, roty, rotz are a, b, c
a, b, c, n = symbols('abcn')
px, py, pz = symbols('px', 'py', 'pz')
qx, qy, qz = symbols('qx', 'qy', 'qz')
tx, ty, tz = symbols('tx', 'ty', 'tz')

R = Matrix([[1, -c, b], [c, 1, -a], [-b, a, 1]])
P = Matrix([px, py, pz])
Q = Matrix([qx, qy, qz])
T = Matrix([tx, ty, tz])

# latex 
E = R*P + T - Q # this says that Q is the map, and P is the scan (i.e. transform P to fit Q)
E = E.T*E
E = E[0]

dofs = Matrix([a, b, c, tx, ty, tz])
partials = Matrix([expand(diff(E, d)/2) for d in dofs])
A = zeros((6, 6))
B = zeros((6, 1))
for i, p in enumerate(partials):
    for j, dd in enumerate(dofs):
        co = p.coeff(dd)
        if co == None: co = 0
        A[i, j] = co

B = partials - A*dofs
B.simplify()
# Now in the form A x + B = 0
# x is dofs
print 'For one point'
print 'A\n', A
print 'B\n', B
#print 'Inverse: ', A.inv()
# sum over i of (A) * dofs + sum over i of (B) = 0
# A is symmetric, so Cholesky decomposition is the preferred algorithm

# alternatively just use x = linalg.solve(A, -B)

