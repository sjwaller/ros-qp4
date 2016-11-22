cmake_minimum_required(VERSION 2.8.3)
project(qp4_moveit)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  moveit_core
  moveit_ros_planning_interface
)

###################################
## catkin specific configuration ##
###################################

catkin_package()

###########
## Build ##
###########

# Enable C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(moveit_api_test src/moveit_api_test.cpp)

target_link_libraries(moveit_api_test ${catkin_LIBRARIES})

#############
## Install ##
#############

install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  PATTERN "setup_assistant.launch" EXCLUDE)
install(DIRECTORY config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
