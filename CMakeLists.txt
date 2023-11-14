cmake_minimum_required(VERSION 2.8.3)
project(moveit_interface)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
  COMPONENTS
    moveit_core
    moveit_ros_planning_interface
)

catkin_package(
  CATKIN_DEPENDS
    moveit_core
    moveit_ros_planning_interface
)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

add_executable(move_to_pose src/moveit_interface.cpp)
target_link_libraries(move_to_pose ${catkin_LIBRARIES})
install(TARGETS move_to_pose DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

