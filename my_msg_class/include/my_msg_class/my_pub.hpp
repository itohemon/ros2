#include <rclcpp/rclcpp.hpp>
#include <my_messages/msg/two_ints.hpp>

class MyPub : public  rclcpp::Node {
private:
  rclcpp::Publisher<my_messages::msg::TwoInts>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
public:
  MyPub();
};
