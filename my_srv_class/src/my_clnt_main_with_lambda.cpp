#include <rclcpp/rclcpp.hpp>
#include <my_srv_class/my_clnt_with_lambda.hpp>

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyClnt>());
    rclcpp::shutdown();

    return 0;
}

