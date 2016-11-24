#QP4 Robot

This is a ROS Kinetic project for my QP4 robot.

<img src="/assets/images/rviz_screenshot_2016_11_17-18_08_41.png" alt="alt text" width="49%" >
<img src="/assets/images/urdf.png" alt="alt text" width="49%" >

#Using ROS Kinetic

__Load robot description and start state publishers__
~~~~
roslaunch qp4_launch qp4_pubs.launch
~~~~

__Teleop__

Run the Teleop node for PS3 Controller input - see links for running ps3joy as daemon
~~~~
roslaunch qp4_launch qp4_teleop.launch 
~~~~

__Visualise robot using URDF__

Display gui for joint position sliders (joint_state_publisher)
~~~~
roslaunch qp4_launch qp4_pubs.launch gui:=true
~~~~

Start RViz
~~~~
roslaunch qp4_launch qp4_rviz.launch
~~~~

__Start Gazebo with empty world__

Loads qp4.world from qp4_description/worlds folder
~~~~
roslaunch qp4_launch qp4_gazebo.launch
~~~~

__MoveIt!__

Start MoveIt setup assistant
~~~~
roslaunch moveit_setup_assistant setup_assistant.launch
~~~~

Start MoveIt demo in RViz
~~~~
roslaunch qp4_moveit demo.launch
~~~~

Run the MoveIt RViz plugin with default database
~~~~
roslaunch qp4_moveit demo.launch db:=true                            # Start RViz with MoveIt MotionPlanning plugin and default database
~~~~

Run the MoveIt RViz plugin with custom database
~~~~
roslaunch qp4_moveit demo.launch db:=true db_path:=~/qp4_warehouse_mongo_db
~~~~

Test MoveIt Move Group API
~~~~
rosrun qp4_moveit moveit_api_test                                           # Run test program: MoveIt Move Group Interface/C++ API
~~~~


__Scripts__

Build urdf
~~~~
./urdf/generate_urdf_and_vis.sh
~~~~



#Links

* http://wiki.ros.org/urdf/Tutorials
* http://gazebosim.org/tutorials?tut=ros_urdf
* http://www.lynxmotion.com/s-5-ses-3d-models.aspx
* http://wiki.ros.org/ps3joy/Tutorials/Running%20ps3joy.py%20as%20daemon
