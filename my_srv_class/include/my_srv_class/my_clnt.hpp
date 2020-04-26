#include <rclcpp/rclcpp.hpp>
#include <my_messages/srv/calc_two_floats.hpp>

class MyClnt : public rclcpp::Node {
private:
    // client用の設定変数
    rclcpp::Client<my_messages::srv::CalcTwoFloats>::SharedPtr clnt_;
    // Timerの設定
    rclcpp::TimerBase::SharedPtr timer_;
    void callback_timer_();
    // 非同期処理のためのcallback関数
    void callback_response_(rclcpp::Client<my_messages::srv::CalcTwoFloats>::SharedFuture future);
public:
    MyClnt();
};

