#include <rclcpp/rclcpp.hpp>

class MinimalParamClient : public rclcpp::Node {
private:
    rclcpp::SyncParametersClient::SharedPtr param_;
public:
    MinimalParamClient();
};

