from H3DInterface import*

class button(TypedField(SFString, SFBool, SFVec3f)):
	def update(self, event):
		input = self.getRoutesIn()
		pressed = input[0].getValues()
		position=input[1].getValues()
		if (pressed == 0):
			return SFVec3f(0,0,0)
		else:
			return position
			
push=button()