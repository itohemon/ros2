#include <rclcpp/rclcpp.hpp>
#include <minimal_subscriber_class_node/minimal_subscriber.hpp>

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  // nodeを作ってspinに渡す。Nodeではなく、自分で作成したクラスなので
  // std::make_sharedになる
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();

  return 0;
}
