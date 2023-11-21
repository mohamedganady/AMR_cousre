#include "ros/ros.h"
#include "std_msgs/Int32.h"

int sub ;
void FUNCallBack (const std_msgs::Int32::ConstPtr& msg )
{
     msg->data;
}

int main(int argc , char** argv)
{
    ros::init(argc , argv , "integer_subscriber");

    ros::NodeHandle n;

    ros::Subscriber sub ;

    sub = n.subscribe("integer_topic" , 1000 , FUNCallBack);

    ros::spin();

    return 0;
}
