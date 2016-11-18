# Using ROS Kinetic

roscd qp4_master
./urdf/generate_urdf_and_vis.sh

## Simulated robot ##
# Load robot description and start state publishers
roslaunch qp4_master qp4_pubs.launch

# Visualise robot using URDF
roslaunch qp4_master qp4_pubs.launch gui:=true   				    # Display gui for joint position sliders (joint_state_publisher)
roslaunch qp4_master qp4_rviz.launch model:=urdf/qp4.urdf  			# Start RViz

# Start Gazebo with empty world
roslaunch qp4_master qp4_gazebo.launch                              # Loads qp4.world from qp4_master/worlds folder



