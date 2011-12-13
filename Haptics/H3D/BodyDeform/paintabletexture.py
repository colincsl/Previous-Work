from H3DInterface import *

# This field class just takes the first value of its input MField 
# and uses it as output
class FirstTouchTexCoord( TypedField( SFVec3f, MFVec3f ) ):
  def update( self, event ):
    tex_coords = event.getValue()
    if( len(tex_coords) > 0 ):
      return tex_coords[0]
    else:
      return Vec3f( 0, 0, 0 )

firstTexCoord = FirstTouchTexCoord()    