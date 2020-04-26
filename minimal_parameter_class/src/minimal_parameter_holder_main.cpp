#include <rclcpp/rclcpp.hpp>
#include <minimal_parameter_class/minimal_parameter_holder.hpp>

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalParameterHolder>());
    rclcpp::shutdown();

    return 0;
}

