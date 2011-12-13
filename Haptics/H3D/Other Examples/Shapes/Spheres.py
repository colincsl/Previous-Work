import random
from H3DInterface import*

#get reference to group
group, = references.getValue()

#create sphere
sphere = createX3DNodeFromString("""<Sphere radius = ".02"/>""")[0]

##Create new spheres
class AddSphere(AutoUpdate(SFBool)):
    def update(self, event):
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
        t.translation.setValue(Vec3f(c.r*0.5 - 0.25,
                                     c.g*0.5 - 0.25,
                                     c.b*0.5 - 0.25))
        group.children.push_back(t)
        return event.getValue()

#create new sphere
add_sphere = AddSphere()
