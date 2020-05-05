#include <chrono>   // ROS2で時間を扱うために必要
#include <memory>   // shared_ptrを扱うために必要

#include <rclcpp/rclcpp.hpp>        // rclcppのインクルード
#include <std_msgs/msg/string.hpp>  // ROSのstd_msgsメッセージ型を扱うための宣言

int main(int argc, char* argv[])
{
    using namespace std::chrono_literals;

    rclcpp::init(argc, argv);       // rclcppの初期化, まずはじめに実行します

    // std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("my_pub1");// Nodeの実体を作成
    // rclcpp::Node* node = new rclcpp::Node("my_pub1");// Nodeの実体を作成
    auto node = rclcpp::Node::make_shared("my_pub1");// Nodeの実体を作成

    std::shared_ptr< rclcpp::Publisher<std_msgs::msg::String>> pub
        = node->create_publisher<std_msgs::msg::String>("test_topic", 10 );   // NodeにPublisherを作成(トピック名, QoSの履歴数)

    uint32_t count = 0;             // トピック用のカウンタ
    rclcpp::WallRate rate(2);   // 周期タイマ（500msec毎,2Hz）

    while( rclcpp::ok() ){          // CTRL+Cされるまでループ
        std_msgs::msg::String test_str;

        test_str.data = "Test String " + std::to_string(count++);// Publishする文字列作成
        pub->publish( test_str );   // Publishする
        rate.sleep();               // 周期街
    }
    rclcpp::shutdown();             // ノード間通信の終了

    return 0;                       // プログラム終了
}
