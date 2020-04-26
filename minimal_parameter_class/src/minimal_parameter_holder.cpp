#include <rclcpp/rclcpp.hpp>
#include <minimal_parameter_class/minimal_parameter_holder.hpp>

// node名：param_holderのノードを作成
MinimalParameterHolder::MinimalParameterHolder()
: Node("param_holder") {
    using namespace std::chrono_literals;
    
    // 設定するparameterの宣言
    auto param1 = declare_parameter("foo", 0);
    auto param2 = declare_parameter("bar", "ok");
    auto results = set_parameters({
        rclcpp::Parameter("foo", 2),
        rclcpp::Parameter("bar","hello")
    });
}
