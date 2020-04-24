#include <rclcpp/rclcpp.hpp>
#include "minimal_node.hpp"

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    // nodeの作成。自分のクラスなのでNodeのmake_sharedではなく
    // stdのmake_sharedを使って実体化
    auto node = std::make_shared<MinimalNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

