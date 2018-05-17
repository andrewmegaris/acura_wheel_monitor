#include <ros/ros.h>
#include <std_msgs/String.h>
#include <can_msgs/Frame.h>
#include <cmath>

class subAndPub
{
public:

  //SubAndPub constructor definition
  subAndPub()
  {        
    //set up.
    pubSteering = nh.advertise<std__msgs::Float32>("steering_angle", 10);

    //Subscribe to whatever topic is publishing the CAN frames
    //if you use 'rosrun socketcan_bridge socketcan_to_topic' that is 'received_messages'
    sub = nh.subscribe("received_messages", 10, &subAndPub::callback, this);

  }

  void callback(const can_msgs::Frame& input)
  {
    ros::Rate publish_rate(10);   

    if (input.frame_id == //TODO Steering frame.)
    {
      
      //TODO convert bytes to steering angle. 
      steering_angle.data = input.frame_id[0] + input_frame_id[0];
        while (pubSteering.getNumSubscribers() < 1)
        {
          if (!ros::ok())
          {
            return;
          }
          ROS_WARN_ONCE("Please create a subscriber to the marker array");
          sleep(1);
        }
        pubSteering.publish(steering_angle);
        publish_rate.sleep();
    }
  }

private:
  ros::NodeHandle nh; 
  ros::Publisher  pubSteering;
  ros::Subscriber sub; 
  std_msgs::float32 steering_angle;

};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_n_pub");
  subAndPub mydood;
  ros::spin();
  return 0;
}
