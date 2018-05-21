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


    if (input.id == 464)
    {
      wheel_sensor.header.stamp = ros::Time::now();
   
      
      wheel_sensor.FL_speed = float( (int16_t) ( (input.data[1] >> 1) + (input.data[0] << 7)))                                    * 0.01;
      wheel_sensor.FR_speed = float( (int16_t) ( (input.data[3] >> 2) + (input.data[2] << 6) + ((input.data[1] & 0x01) << 14) ) ) * 0.01;
      wheel_sensor.RL_speed = float( (int16_t) ( (input.data[5] >> 3) + (input.data[4] << 5) + ((input.data[3] & 0x03) << 13) ) ) * 0.01;
      wheel_sensor.RR_speed = float( (int16_t) ( (input.data[7] >> 4) + (input.data[6] << 4) + ((input.data[5] & 0x07) << 12) ) ) * 0.01;

      pubWheels.publish(wheel_sensor);
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
