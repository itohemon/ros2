#include <rclcpp/rclcpp.hpp>
#include <my_messages/srv/calc_two_floats.hpp>

class MySrv : public rclcpp::Node {
private:
    rclcpp::Service<my_messages::srv::CalcTwoFloats>::SharedPtr srv_;
    void handleService_(
        const std::shared_ptr<rmw_request_id_t> request_header,
        const std::shared_ptr<my_messages::srv::CalcTwoFloats::Request> request,
        const std::shared_ptr<my_messages::srv::CalcTwoFloats::Response> response
    );
public: 
    MySrv(); 
};
