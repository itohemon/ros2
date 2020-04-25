#include <rclcpp/rclcpp.hpp>
#include "my_messages/msg/two_ints.hpp"
#include <my_msg_class/my_sub.hpp>

MySub::MySub()
  : Node("my_sub_test") {
  sub_ = this->create_subscription<my_messages::msg::TwoInts>(
    "msg_test",
    [this](const my_messages::msg::TwoInts::SharedPtr msg) ->void {
        RCLCPP_INFO(this->get_logger(), "Sub: %d, %d", msg->a, msg->b);
	}
	);
}
