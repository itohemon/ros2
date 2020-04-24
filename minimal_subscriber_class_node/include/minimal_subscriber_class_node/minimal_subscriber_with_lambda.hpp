#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class MinimalSubscriber : public rclcpp::Node {
private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
public:
  MinimalSubscriber();
};
