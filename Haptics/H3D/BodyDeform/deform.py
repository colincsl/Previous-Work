from H3DInterface import *

# make sure the proxy is drawn at the position of the haptics device
di = getActiveDeviceInfo()
if( di ):
  devices = di.device.getValue()
  for d in devices:
    d.proxyWeighting.setValue( 0 )

# This python file creates an rectangular IndexedTriangleSet with
# columns X rows coordinates.
#columns = 31
#rows = 31
#size = Vec2f( 0.4, 0.4 )



deform_node,coords_in = references.getValue()

#for i in range(0, coords_in.point, 3)
#coord_vec = 

its =  createX3DNodeFromString( "<IndexedFaceSet  solid=\"FALSE\" />" )[0]
coord = createX3DNodeFromString( "<Coordinate />" )[0]

#for i in coord.points
#	c_in.append(coord.points[i])
#coord.point.setValue( coords_in.point )

#tex_coord = createX3DNodeFromString( "<TextureCoordinate />" )[0]
#tex_coord.point.setValue( tex_coords )

its.coord.setValue( coords_in.point ) 
#its.texCoord.setValue( tex_coord )

deform_node.geometry.setValue( its )