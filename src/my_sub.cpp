#include "ros2_training/my_sub.hpp"

int main ( int argc, char* argv[])
{
    rclcpp::init( argc, argv );
    rclcpp::spin( std::make_shared<MySubscriber>("my_sub","test_topic") );
    rclcpp::shutdown();

    return 0 ;
}