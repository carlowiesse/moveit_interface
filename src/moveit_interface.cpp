#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "move_to_pose");
  geometry_msgs::Pose move_target;
  std::string move_frame;

  if(argc == 9) {
    move_target.position.x = atof(argv[1]);
    move_target.position.y = atof(argv[2]);
    move_target.position.z = atof(argv[3]);
    move_target.orientation.x = atof(argv[4]);
    move_target.orientation.y = atof(argv[5]);
    move_target.orientation.z = atof(argv[6]);
    move_target.orientation.w = atof(argv[7]);
    move_frame = argv[8].c_str();
  } else {
    printf("Usage: move_to_pose x y z qx qy qz qw frame_id \n");
    ROS_ERROR("move_to_pose exited due to not having the right number of arguments");
    return -1;
  }
  ROS_INFO("Move to : x=%f, y=%f, z=%f w.r.t %s",move_target.position.x,move_target.position.y,move_target.position.z,move_frame);
  // printf("Got move_target !\n");

  ros::AsyncSpinner spinner(1);
  spinner.start();

  static const std::string PLANNING_GROUP = "manipulator";
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);

  // move_target = move_group.getCurrentPose().pose;
  // move_target.position.z -= 0.2; // down
  // move_target.position.y -= 0.2; // right
  // move_target.position.x -= 0.2; // back
  // move_frame = move_group.getCurrentPose().header.frame_id;

  // Plan for robot to move to part
  move_group.setPoseReferenceFrame(move_frame);
  move_group.setPoseTarget(move_target);
  move_group.move();

  ros::waitForShutdown();
  // ros::shutdown();
  return 0;
}
