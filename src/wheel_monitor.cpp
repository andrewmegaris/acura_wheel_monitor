#include <ros/ros.h>
#include <can_msgs/Frame.h>
#include <wheel_monitor/Wheels.h>
#include <cmath>

class subAndPub
{
public:

  //SubAndPub constructor definition
  subAndPub()
  {         
    //set up.
    pubWheels = nh.advertise<wheel_monitor::Wheels>("wheel_speeds", 10);
    wheel_sensor.header.frame_id = "/controls";

    //Subscribe to whatever topic is publishing the CAN frames
    //if you use 'rosrun socketcan_bridge socketcan_to_topic' that is 'received_messages'
    sub = nh.subscribe("received_messages", 10, &subAndPub::callback, this);

  }

  void callback(const can_msgs::Frame& input)
  {
    ros::Rate publish_rate(1);   

    if (input.id == 464)
    {
      wheel_sensor.header.stamp = ros::Time::now();
      //WE CAN DO A CHECKSUMMM
      wheel_sensor.FL_speed      = float(((int16_t)((input.data[0] << 8) + input.data[1])) * -0.1 );
      wheel_sensor.FR_speed      = float(((int16_t)((input.data[0] << 8) + input.data[1])) * -0.1 );
      wheel_sensor.RL_speed      = float(((int16_t)((input.data[0] << 8) + input.data[1])) * -0.1 );
      wheel_sensor.RR_speed      = float(((int16_t)((input.data[0] << 8) + input.data[1])) * -0.1 );
      std::cout << "hit dem wheelz yo" << std::endl;
      pubWheels.publish(wheel_sensor);
      publish_rate.sleep();
    }
  }

private:
  ros::NodeHandle nh; 
  ros::Publisher  pubWheels;
  ros::Subscriber sub; 
  wheel_monitor::Wheels wheel_sensor;

};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_n_pub");
  subAndPub mydood;
  ros::spin();
  return 0;

}   
