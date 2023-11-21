#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard the message [%s]" , msg->data.c_str());
}


int main (int argc , char **argv)
{
    ros::init(argc, argv , "listener");

    ros::NodeHandle n;

    ros::Subscriber sub ;

    sub = n.subscribe("chatter", 1000 , chatterCallback);

    ros::spin();  //Spin, waiting for messages to arrive

    return 0;
}
