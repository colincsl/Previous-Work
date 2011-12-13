from H3DInterface import *

#dev_info = getActiveDeviceInfo()
#device = dev_info.device.getValue()[0]


class X_fun( TypedField(SFString, SFBool)):
    def update(self, event):
        routes_in = self.getRoutesIn()
        button = routes_in[0].getValue()
        if(button):
            return "-200*x"
        else:
            return "0"


##class Y_fun(TypedField(SFString, SFBool)):
##    def update(self, event):
##        routes_in = self.getRoutesIn()
##        button = routes_in[0].getValue()
##        if(button):
##            return "-200*y"
##        else:
##            return "0"
##
##class Z_fun(TypedField(SFString, SFBool)):
##    def update(self, event):
##        routes_in = self.getRoutesIn()
##        button = routes_in[0].getValue()
##        if(button):
##            return "-200*z"
##        else:
##            return "0"
        

x_but = X_fun()
#y_but = Y_fun()
#z_but = Z_fun()

