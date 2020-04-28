#include <rclcpp/rclcpp.hpp>
#include <minimal_comp/minimal_comp_node1.hpp>
#include <minimal_comp/minimal_comp_node2.hpp>

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::executors::SingleThreadedExecutor exec;

    auto node1 = std::make_shared<minimal_comp::MinimalCompNode1>();
    exec.add_node(node1);
    auto node2 = std::make_shared<minimal_comp::MinimalCompNode2>();
    exec.add_node(node2);

    exec.spin();
    rclcpp::shutdown();

    return 0;
}

