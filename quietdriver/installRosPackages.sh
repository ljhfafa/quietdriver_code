#!/bin/bash
# Author: Matt Bunting, Matt Nice

echo "----------------------------"
if [[ $EUID == 0 ]];
  then echo "Do NOT run this script as root"
  exit
fi

echo "Installing/Updating {APP_NAME_PRETTY} packages"

source ~/.bashrc

LIBPANDA_SRC=$(cat /etc/libpanda.d/libpanda_src_dir)


cd ~
if [ ! -d catkin_ws/src ]; then
    mkdir -p catkin_ws/src
fi

cd ~/catkin_ws
source /opt/ros/noetic/setup.bash

echo "Regenerating CanToRos"
cd ~/catkin_ws/src/can_to_ros/scripts
echo y | ./regenerateCanToRos.sh


# Build:
source ~/catkin_ws/devel/setup.sh
cd ~/catkin_ws
catkin_make


echo "Enabling can_to_ros startup script"
sudo systemctl daemon-reload
sudo systemctl enable quietdriver



echo "----------------------------"
