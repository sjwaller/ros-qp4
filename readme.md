#QP4 Robot

This is a ROS Kinetic project for my QP4 robot.

<img src="/assets/images/rviz_screenshot_2016_11_17-18_08_41.png" alt="alt text" width="49%" >
<img src="/assets/images/urdf.png" alt="alt text" width="49%" >

#Using ROS Kinetic

__Load robot description and start state publishers__
~~~~
roslaunch qp4_master qp4_pubs.launch
~~~~

__Visualise robot using URDF__

Display gui for joint position sliders (joint_state_publisher)
~~~~
roslaunch qp4_master qp4_pubs.launch gui:=true
~~~~

Start RViz
~~~~
roslaunch qp4_master qp4_rviz.launch model:=urdf/qp4.urdf
~~~~

__Start Gazebo with empty world__

Loads qp4.world from qp4_master/worlds folder
~~~~
roslaunch qp4_master qp4_gazebo.launch
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

