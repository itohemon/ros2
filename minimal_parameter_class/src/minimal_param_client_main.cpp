#include <rclcpp/rclcpp.hpp>
#include <minimal_parameter_class/minimal_param_client.hpp>

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalParamClient>());
    rclcpp::shutdown();

    return 0;
}
