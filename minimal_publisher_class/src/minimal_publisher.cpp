#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <minimal_publisher_class/minimal_publisher.hpp>

using namespace std::chrono_literals;

MinimalPublisher::MinimalPublisher()
  : Node("minimal_publisher"), count_(0) {
  publisher_ = this->create_publisher<std_msgs::msg::String>("topic_test", 10);
  timer_ =  this->create_wall_timer(
				    500ms, // 実行周期500ms
				    [this]() { // コールバック関数
				      auto msg = std::make_shared<std_msgs::msg::String>();
				      msg->data = "Hello " + std::to_string(count_++);
				      RCLCPP_INFO(this->get_logger(), "Pub:%s", msg->data.c_str());
				      publisher_->publish(*msg);
				    }
				    );
}
