#include <rclcpp/rclcpp.hpp>
#include "minimal_class_node/minimal_node.hpp"

MinimalNode::MinimalNode(const rclcpp::NodeOptions& options)
: MinimalNode("", options) {}

MinimalNode::MinimalNode(const std::string& name_space, const rclcpp::NodeOptions& options) 
: Node("minimal_node_test", name_space, options) {
    RCLCPP_INFO(this->get_logger(), "minimal_node_test");
}
