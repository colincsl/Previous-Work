//Colin Lea
//ARM Lab, University at Buffalo
//This example creates a haptic spring that is placed at a user defined location
//It is based on the example included in HAPI/examples


#include <HAPI/HapticPositionFunctionEffect.h>
#include <HAPI/ParsedFunction.h>
#include <HAPI/AnyHapticsDevice.h>
#include <String.h>

using namespace HAPI;

int main(int argc, char* argv[])
{
	HAPIFloat x=0, y=0, z=0;
	AnyHapticsDevice hd;
	string func_x;
	HAPIFloat eval_x;

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

		//add effect to haptics
		
		ParsedFunction i1;
	    //i1 = new ParsedFunction();
		func_x = "1";
		eval_x = 1.0;
		i1.setFunctionString(func_x);
		i1.evaluate(&eval_x);
		
		HapticPositionFunctionEffect f = new HapticPositionFunctionEffect(i1,i1,i1);
		//HapticSpring *spring = new HapticSpring(Vec3(x,y,z), spring_constant);
		//hd.addEffect(spring);
		hd.addEffect(f)
		hd.transferObjects();

		cout<<"Press enter to change position and spring constant"<<endl;
		getline(cin, thePosition);
	hd.removeEffect(f);
	hd.transferObjects();
}
hd.disableDevice();
hd.releaseDevice();
}