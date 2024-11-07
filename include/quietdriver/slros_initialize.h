#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "quietdriver_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block quietdriver/car-speed
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Sub_quietdriver_80;

// For Block quietdriver/space-gap
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Sub_quietdriver_82;

// For Block quietdriver/space-gap1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Sub_quietdriver_83;

// For Block quietdriver/speed-gap
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Sub_quietdriver_81;

// For Block quietdriver/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_quietdriver_std_msgs_Float64> Pub_quietdriver_84;

void slros_node_init(int argc, char** argv);

#endif
