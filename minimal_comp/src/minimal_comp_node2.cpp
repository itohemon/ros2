#include <rclcpp/rclcpp.hpp>
#include <minimal_comp/minimal_comp_node2.hpp>

namespace minimal_comp {

MinimalCompNode2::MinimalCompNode2()
: Node("minimal_comp2")
{
    RCLCPP_INFO(this->get_logger(), "minimal comp 2 test");
}

}

