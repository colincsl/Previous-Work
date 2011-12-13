from H3DInterface import *

aud=SFBool("1")

class audio(TypedField(SFString, MFBool)):
	def update(self, event):
		inputs=self.getRoutesIn()
		touched=inputs[0].getValue()
		if(touched):
			return SFBool("1")
		else:
			return SFBool("0")
			
aud=audio()