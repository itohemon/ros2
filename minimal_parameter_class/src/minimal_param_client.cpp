#include <rclcpp/rclcpp.hpp>
#include <minimal_parameter_class/minimal_param_client.hpp>

MinimalParamClient::MinimalParamClient()
: Node("param_client") {
    using namespace std::chrono_literals;
    param_ = std::make_shared<rclcpp::SyncParametersClient>(this, "param_client");
    std::stringstream ss;

    while (!param_->wait_for_service(1s)) {
        RCLCPP_INFO(this->get_logger(), "waiting for service");
    }

    auto parameters_get_results = param_->get_parameters({"foo", "bar"});
    for (auto &param : parameters_get_results) {
        ss << "\nParameter name: " << param.get_name();
        ss << "\nParameter type: " << param.get_type_name();
        ss << "\nParameter value: " << param.value_to_string();
    }

    RCLCPP_INFO(this->get_logger(), ss.str().c_str());
    ss.str("");
    ss.clear(std::stringstream::goodbit);

    auto list_results = param_->list_parameters({"foo", "bar"}, 10);
    for (auto &param_name : list_results.names) {
        ss << "\n" << param_name;
    }
    for (auto &prefix : list_results.prefixes) {
        ss << "\n" << prefix;
    }
    RCLCPP_INFO(this->get_logger(), ss.str().c_str());
    ss.str("");
    ss.clear(std::stringstream::goodbit);

    auto parameter_set_results = param_->set_parameters({
        rclcpp::Parameter("foo", 3),
        rclcpp::Parameter("bar", "welcome")
    });
    for (auto &result : parameter_set_results) {
        if (!result.successful) {
            RCLCPP_ERROR(this->get_logger(), "Failed to set parameter: %s", result.reason.c_str());
        }
    }

    parameters_get_results = param_->get_parameters({"foo", "bar"});
    for (auto &param : parameters_get_results) {
        ss << "\nParameter name: " << param.get_name();
        ss << "\nParameter type: " << param.get_type_name();
        ss << "\nParameter value: " << param.value_to_string();
    }
    RCLCPP_INFO(this->get_logger(), ss.str().c_str());
    ss.str("");
    ss.clear(std::stringstream::goodbit);
}

