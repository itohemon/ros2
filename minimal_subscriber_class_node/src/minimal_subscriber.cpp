#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <minimal_subscriber_class_node/minimal_subscriber.hpp>

// callback関数の定義
void MinimalSubscriber::topic_callback_(const std_msgs::msg::String::SharedPtr msg) {
  RCLCPP_INFO(this->get_logger(), "I heard: %s", msg->data.c_str());
}

// クラスの定義。Nodeに"名前"を渡して初期化
MinimalSubscriber::MinimalSubscriber()
  : Node("minimal_subscriber_test") {
  // subscriberとしての設定。
  subscription_ = 
    this->create_subscription<std_msgs::msg::String>(
						     "topic_test",
						     std::bind(&MinimalSubscriber::topic_callback_, this, std::placeholders::_1)
						     );
}

						     

