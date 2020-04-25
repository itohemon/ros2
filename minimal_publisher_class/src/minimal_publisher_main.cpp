#include <rclcpp/rclcpp.hpp>
#include <minimal_publisher_class/minimal_publisher.hpp>

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
