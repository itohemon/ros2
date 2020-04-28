#include <rclcpp/rclcpp.hpp>
#include <minimal_comp/minimal_comp_node1.hpp>

namespace minimal_comp {

MinimalCompNode1::MinimalCompNode1()
: Node("minimal_comp1")
{
    RCLCPP_INFO(this->get_logger(), "minimal comp 1 test");
}

}

