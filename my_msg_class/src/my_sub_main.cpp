#include <rclcpp/rclcpp.hpp>
#include <my_msg_class/my_sub.hpp>

int main(int argc, char * argv[]){
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MySub>());
  rclcpp::shutdown();

  return 0;
}
