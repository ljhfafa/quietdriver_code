#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "quietdriver";

// For Block quietdriver/car-speed
SimulinkSubscriber<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Sub_quietdriver_80;

// For Block quietdriver/space-gap
SimulinkSubscriber<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Sub_quietdriver_82;

// For Block quietdriver/speed-gap
SimulinkSubscriber<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Sub_quietdriver_81;

// For Block quietdriver/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Pub_quietdriver_84;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

