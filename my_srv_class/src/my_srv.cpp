#include <rclcpp/rclcpp.hpp>
#include <my_srv_class/my_srv.hpp>
#include <my_messages/srv/calc_two_floats.hpp>

void MySrv::handleService_(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<my_messages::srv::CalcTwoFloats::Request> request,
    const std::shared_ptr<my_messages::srv::CalcTwoFloats::Response> response
) {
    (void)request_header;
    RCLCPP_INFO(this->get_logger(), "srv.request: %lf, %lf", request->a, request->b);
    response->sum = request->a + request->b;
    response->diff = request->a - request->b;
}

MySrv::MySrv()
: Node("minimal_service") {
    using namespace std::placeholders;

    srv_ = this->create_service<my_messages::srv::CalcTwoFloats>(
        "srv_test",
        std::bind(&MySrv::handleService_, this, _1, _2, _3)
    );
}

