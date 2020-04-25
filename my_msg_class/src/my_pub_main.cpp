#include <rclcpp/rclcpp.hpp>
#include <my_msg_class/my_pub.hpp>

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MyPub>());
  rclcpp::shutdown();

  return 0;
}
