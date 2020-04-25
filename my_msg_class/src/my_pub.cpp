#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include "my_messages/msg/two_ints.hpp"
#include <my_msg_class/my_pub.hpp>

MyPub::MyPub()
  :Node("my_pub_test") {
  using namespace std::chrono_literals;
  pub_ = this->create_publisher<my_messages::msg::TwoInts>("msg_test");
  timer_ = this->create_wall_timer(
   500ms,
   [this]()->void{
        auto msg = std::make_shared<my_messages::msg::TwoInts>();
        msg->a = 3;
	    msg->b = 4;
	    RCLCPP_INFO(this->get_logger(), "Pub: %d, %d", msg->a, msg->b);
	    pub_->publish(*msg);
    }
    );
}

