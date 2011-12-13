//Colin Lea
//ARM Lab, University at Buffalo
//This example creates a haptic spring that is placed at a user defined location


#include <HAPI/HapticSpring.h>
#include <HAPI/AnyHapticsDevice.h>

using namespace HAPI;

int main(int argc, char* argv[])
{

	AnyHapticsDevice hd;

	//initialize. return error and exit if there is a failure
	if (hd.initDevice() !=HAPIHapticsDevice::Success)
	{
		cerr <<hd.getLastErrorMsg() <<endl;
		system("PAUSE");
		return 0;
	}

	hd.enableDevice(); //enable

	bool continue_trying = true;

	while(continue_trying)
	{
		cout<<"Enter position (0<q<0.1) for x, y, z"<<endl;
		cout<<"100 is relatively weak, 1000 is strong"<<edl;
		getline(cin, thePosition);
		HAPIFloat spring_constant = strtod(thePosition.c_str(), NULL);

		stringstream stm_x, stm_y, stm_z, stm_const;
		stm_x << x;
		stm_y << y;
		stm_z << z;
		stm_const << spring_constant;

		//add spring to haptics
		HapticSpring *spring = new HapticSpring(Vec3(x,y,z), spring_constant);
		hd.addEffect(spring);
		hd.transferObjects();

		cout<<"Press enter to change position and spring constant"<<endl;
		getline(cin, thePosition);
	hd.removeEffect(spring);
	hd.transferObjects();
}
hd.disableDevice();
hd.releaseDevice();