#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class MinimalPublisher : public rclcpp::Node {
private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  // Timer系での定期実行のためのTimerBas型のポインタ
  rclcpp::TimerBase::SharedPtr timer_;
  // 何回目のメッセージ化を表すためのcount_
  size_t count_;

public:
  MinimalPublisher();
};
