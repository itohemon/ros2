#include <rclcpp/rclcpp.hpp>
#include <my_srv_class/my_clnt.hpp>
#include <my_messages/srv/calc_two_floats.hpp>

using namespace std::chrono_literals;

void MyClnt::callback_timer_() {
    // serviceへの接続確認
    while (!clnt_->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(this->get_logger(), "Client interrupted while waiting for service");
            return;
         }
        RCLCPP_INFO(this->get_logger(), "waiting for service...");
    }

    // serviceに送信するデータの準備
    auto request = std::make_shared<my_messages::srv::CalcTwoFloats::Request>();
    request->a = 10.0;
    request->b = 11.2;

    // async_send_request関数に対してserviceに送るデータ(request)に
    // 加えて、serviceからのデータ受信に対する処理を
    // callback関数(callback_response_)を引数として持つ
    auto future_res = clnt_->async_send_request(request, std::bind(&MyClnt::callback_response_, this, std::placeholders::_1));
}

void MyClnt::callback_response_(rclcpp::Client<my_messages::srv::CalcTwoFloats>::SharedFuture future) {
    RCLCPP_INFO(this->get_logger(), "res::%lf, %lf", future.get()->sum, future.get()->diff);
}

MyClnt::MyClnt()
: Node("minimal_client") {
    clnt_ = this->create_client<my_messages::srv::CalcTwoFloats>("srv_test");
    // 1sごとにserviceにメッセージを送るためのcallback_timer_関数を割り当て
    timer_ = this->create_wall_timer(
        1s,
        std::bind(&MyClnt::callback_timer_, this)
    );
}

