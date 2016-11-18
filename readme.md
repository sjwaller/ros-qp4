#Using ROS Kinetic

roscd qp4_master

./urdf/generate_urdf_and_vis.sh

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

#Links

* http://wiki.ros.org/urdf/Tutorials
* http://gazebosim.org/tutorials?tut=ros_urdf

* http://www.lynxmotion.com/s-5-ses-3d-models.aspx

