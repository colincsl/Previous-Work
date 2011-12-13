from H3DInterface import *

class audio(TypedField(SFString, MFBool)):
	def update(self, event):
		input=self.getRoutesIn()
		touched = input[0].getValues()
		if(touched):
			a = createX3DNodeFromString(" \
				<Sound intensity=\"1\"> \
					<AudioClip DEF=\"AUDIO\" url=\"C:\H3D\CLEA\Sound\knocking.wav\" loop=\"false\"/>\
				</Sound>")
			return 0
		else:
			return 0
			
aud=audio()