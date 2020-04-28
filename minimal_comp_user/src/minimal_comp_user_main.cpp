#include <rclcpp/rclcpp.hpp>
#include <minimal_comp/minimal_comp_node2.hpp>

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<minimal_comp::MinimalCompNode2>());
    rclcpp::shutdown();

    return 0;
}

