#include "ros2_training/my_sub.hpp"

int main ( int argc, char* argv[])
{
  rclcpp::init( argc, argv );

  rclcpp::executors::SingleThreadedExecutor exec;   // シングルスレッドExecutor

  auto sub_node1 = std::make_shared<MySubscriber>("my_sub1","test_topic");// ノード1作成
  auto sub_node2 = std::make_shared<MySubscriber>("my_sub2","test_topic");// ノード2作成
  auto sub_node3 = std::make_shared<MySubscriber>("my_sub3","test_topic");// ノード3作成

  exec.add_node( sub_node1 );                       // ノード1をExecutorに登録
  exec.add_node( sub_node2 );                       // ノード2をExecutorに登録
  exec.add_node( sub_node3 );                       // ノード3をExecutorに登録
  exec.spin();                                      // Executorのspinを実行

  rclcpp::shutdown();

  return 0 ;
}