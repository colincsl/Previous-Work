from H3DInterface import *

class X_fun( TypedField(SFString, SFBool)):
    def update(self, event):
        routes_in = self.getRoutesIn()
        button = routes_in[0].getValue()
        if(button):
            return "-200*x"
        else:
            return "0"

x_but = X_fun()

