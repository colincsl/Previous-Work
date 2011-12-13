from H3DInterface import *

class trigger(TypedField(SFBool)):
	def update(self, event):
		input = self.getRoutesIn()
		HDEV, pos = references.getValue()
		button_pressed = HDEV.buttons.getValue()
		run=0
		if button_pressed>0:
			HDEV.devicePosition.route(pos.translation)
		return 0


run=trigger()