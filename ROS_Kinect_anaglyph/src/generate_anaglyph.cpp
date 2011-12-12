

#include <ros/ros.h>
#include "sensor_msgs/Image.h"
#include "image_transport/image_transport.h"
#include "cv_bridge/CvBridge.h"
#include <opencv_core.h>
#include <opencv_highgui.h>

class Anaglyph {

public:

Anaglyph(ros::NodeHandle &n):
	n_(n), it_(n_)
{
	image_pub = it_.advertise("anaglyph_img", 1);

	cvNamedWindow("Image window");
	image_sub_depth_ = it_.subscribe("/kinect/depth/image_raw", &Anaglyph::cb_depth, this);
	image_sub_depth = it_.subscribe("/kinect/rgb/image_raw", &Anaglyph::cb_rgb, this);
}

~Anaglyph()
{
	cvDestroyWindow("Image window");
}

void cb_depth(const sensor_msgs::ImageConstPtr& msg_ptr){
	CvMat *img = NULL;
	img = bridge_.imgMsgToCv(msg_ptr);

	cvShowImage("Image window", img);
	cvWaitKey(3);

	image_pub_.publish(bridge_.cvToImgMsg(img);
}


protected:

ros::NodeHandle n_;
image_transport::ImageTransport it_;
image_transport::Subscriber image_sub_depth_;
image_transport::Subscriber image_sub_rgb_;
sensor_msgs::CvBridge bridge_;
image_transport::Publisher image_pub_;

};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "generate_anaglyph");
	ros::NodeHandle node;
	Anaglyph an(node);
	ros::spin();
	return 0;
}
