##3.13.2017
###install realsense ROS
Only source the system setup file:
source /opt/ros/indigo/setup.bash
Verify this by checking the ROS_PACKAGE_PATH
echo $ROS_PACKAGE_PATH
/opt/ros/indigo/share:/opt/ros/indigo/stacks

Install the released RealSense camera package:
sudo apt-get update
sudo apt-get install ros-indigo-realsense-camera

check version:
	rosversion realsense_camera
	rosversion librealsense


##3.26.2017
###install espeak lib: sudo apt-get install espeak
source code compile: change src/portaudio.h to src/portaudio_old.h 
					 change src/portaudio19.h to src/portaudio.h
g++ test1.c -o test1 -lespeak

##4.11.2017
###install libserial
enable port permission: sudo gpasswd --add ${USER} dialout
install:	./configure 
			make
			make install




