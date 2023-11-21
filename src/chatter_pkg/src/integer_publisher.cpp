#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char** argv)
{
  
  ros::init(argc, argv, "integer_publisher");              /*name of the node*/

  ros::NodeHandle n;

  ros::Publisher pub = n.advertise<std_msgs::Int32>("integer_topic", 10);   /*name of the topic */

  ros::Rate rate(10);         // Publish at 30Hz

  int count = 20;

  while (ros::ok() && count <= 200)
  {
    // Create a message object
    std_msgs::Int32 msg;
    
    msg.data = count;

    // Publish the message
    pub.publish(msg);

    // Increment the count
    count++;

    rate.sleep();
  }

  return 0;
}