## acura_steering:
Ros node that monitors the canbus topic 'received_messages' [can_msgs::Frame](http://docs.ros.org/api/can_msgs/html/msg/Frame.html).  When it reads the can ID for the acura ilx's steering angle.  It will convert it to a float and publish to the 'steering_angle [std_msgs::Float32](http://docs.ros.org/api/std_msgs/html/msg/Float32.htm).

The use of [socketcan_to_topic_node](http://wiki.ros.org/socketcan_bridge?distro=lunar) is recommended for reading the CANBUS and publishing the frames into the ROS network. This node is included in the [ros_canopen package](http://wiki.ros.org/ros_canopen?distro=lunar).
