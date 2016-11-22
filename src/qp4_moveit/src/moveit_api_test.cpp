#include "moveit_api_test.h"
#include "ros/ros.h"
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayTrajectory.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "moveit_api_test");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    ROS_INFO("Sleeping for: %i", 10);
    sleep(10.0);

    bool success;

    ROS_INFO("Loading pose: %s", "sitting_up");

    moveit::planning_interface::MoveGroupInterface robotGroup("robot");

    robotGroup.setNamedTarget("sitting_up");
    moveit::planning_interface::MoveGroupInterface::Plan my_plan1;
    success = robotGroup.plan(my_plan1);
    ROS_INFO("Visualizing move %s", success ? "SUCCESS" : "FAILED");

//    robotGroup.move();

    sleep(100.0);

    ros::shutdown();

    return 0;
}
