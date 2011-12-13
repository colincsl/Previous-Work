//Colin Lea
//ARM Lab, University at Buffalo
//This example creates a haptic spring that is placed at a user defined location
//It is based on the example included in HAPI/examples


#include <HAPI/HapticSpring.h>
#include <HAPI/AnyHapticsDevice.h>
#include <String.h>

using namespace HAPI;

int main(int argc, char* argv[])
{
	HAPIFloat x=0, y=0, z=0;

	AnyHapticsDevice hd;

	//initialize. return error and exit if there is a failure
	if (hd.initDevice() !=HAPIHapticsDevice::SUCCESS)
	{
		cerr <<hd.getLastErrorMsg() <<endl;
		system("PAUSE");
		return 0;
	}

	hd.enableDevice(); //enable

	string thePosition;
	string theSpringConst;
	bool continue_trying = true;

	while(continue_trying)
	{
		cout<<"Enter position 0<n<10 for x, y, z (separate by spaces)"<<endl;
		getline(cin, thePosition);

		char *pEnd;
		x = strtod(thePosition.c_str(), &pEnd);
		y = strtod(pEnd, &pEnd);
		z = strtod(pEnd, NULL);

		x = x/200;
		y = y/200;
		z = z/200;

		cout<<"Enter spring constant:"<<endl;
		cout<<"100 is relatively weak, 1000 is strong"<<endl;
		getline(cin, theSpringConst);
		HAPIFloat spring_constant = strtod(theSpringConst.c_str(), NULL);

		//stringstream stm_x, stm_y, stm_z, stm_const;
		//stm_x << x;
		//stm_y << y;
		//stm_z << z;
		//stm_const << spring_constant;

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
}