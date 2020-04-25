#include <rclcpp/rclcpp.hpp>
#include <chrono>

rclcpp::Node::SharedPtr node = nullptr;

int main(int argc, char *argv[]) {
	// 単位付きの時間を使用するための設定
	using namespace std::chrono_literals;

	rclcpp::init(argc, argv);
	node = rclcpp::Node::make_shared("minimal_node");

	// sleep時間を指定
	rclcpp::WallRate loop_rate(500ms);

	for (int i = 0; i < 3; i++) {
		RCLCPP_INFO(node->get_logger(), "loop: %d", i);
		// sleep実行
		loop_rate.sleep();
	}

	// Timerはノードの機能。
	auto timer1 = node->create_wall_timer(
		1s,		// 実行周期
		[](){
			RCLCPP_INFO(node->get_logger(), "node_loop");
		}		// 定期的に実行したい処理
	);
	rclcpp::spin(node);

	rclcpp::shutdown();
	return 0;
}
