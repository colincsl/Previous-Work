import random
from H3DInterface import *
#get reference to group

mouse = SFVec2f()
print 'mouse'
group,= references.getValue()
#mouse = SFVec2f(0.0)
#mouse = mouse.position



#create sphere
sphere = createX3DNodeFromString("""<Sphere radius = ".02"/>""")[0]

##Create new spheres
class AddSphere(AutoUpdate(SFBool)):
    def update(self, event):
        #r_in = getRoutesIn(self)
        #if(r_in[1]()):
        if(event.getValue()):
            t, dn = createX3DNodeFromString("""\
                <Transform>
                    <Shape DEF = "SHAPE">
                        <Appearance>
                            <Material DEF = "MATERIAL"/>
                        </Appearance>
                    </Shape>
                </Transform>""")
        c = RGB(random.random(), random.random(), random.random())
        dn["MATERIAL"].diffuseColor.setValue(c)
        dn["SHAPE"].geometry.setValue(sphere)
        #mouse = dn["MS"]
        x= mouse.getValue()
        x1= float(x.x) #problem - x is a vec2f
        t.translation.setValue( Vec3f((x1-250)/500, 0.0,
                                      0.0 ) )
        group.children.push_back(t)
        return event.getValue()


#class Mouse(AutoUpdate(SFVec2f)):
#    def update(self, event):
#        m = self.getValue
#        return m

#def Mouse(SFVec2f)
#    m = self.getValue
#    return m

add_sphere = AddSphere()


