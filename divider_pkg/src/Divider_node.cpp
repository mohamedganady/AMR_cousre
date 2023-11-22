#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"


ros :: Publisher pub ;

ros::Subscriber sub ;

std_msgs::Float32 divided_msg;

int input_data;

void DividerCallBack(const std_msgs::Int32::ConstPtr& int_msg)
{
     input_data= int_msg->data;
}

int main (int argc , char** argv )
{

    ros::init(argc, argv , "Divider_node");

    ros::NodeHandle n;

    ros::Rate rate(10);

    pub = n.advertise<std_msgs::Float32>("dived_value", 10);

    sub = n.subscribe("integer_topic", 10 , DividerCallBack);

    while (ros::ok())
    {

    divided_msg.data = float(input_data)/2;

    pub.publish(divided_msg);

    rate.sleep();

    }

    return 0;
}