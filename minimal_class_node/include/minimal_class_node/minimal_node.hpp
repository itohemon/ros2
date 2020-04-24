#include <rclcpp/rclcpp.hpp>

class MinimalNode : public rclcpp::Node {
public:
    // 引数なしで宣言するコンストラクタ
	MinimalNode(
		const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
	);
    // nodeに名前空間をつけるコンストラクタ
	MinimalNode(
		const std::string& name_space,
		const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
	);
};

