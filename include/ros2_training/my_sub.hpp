#include <chrono>                                               // ROS2で時間を扱うために必要
#include <memory>                                               // shared_ptrを扱うために必要

#include <rclcpp/rclcpp.hpp>                                    // rclcppのインクルード
#include <std_msgs/msg/string.hpp>                              // ROSのstd_msgsメッセージ型を扱うための宣言

using namespace std::placeholders;                              // bind用の定義

class MySubscriber : public rclcpp::Node                        // Nodeを継承します
{
public:
    MySubscriber( std::string node_name, std::string topic_name )// コンストラクタ(ノード名,トピック名)
     : Node(node_name)                                          // Nodeの実体を作成
    {
        sub_ = this->create_subscription<std_msgs::msg::String>(// Subscriber作成
            topic_name,                                         // 購読するトピック名設定
            10,                                                 // 購読キューの数
            std::bind( &MySubscriber::callback, this, _1) );    // メッセージ受信で呼び出す関数設定
    }
    void callback(const std_msgs::msg::String::SharedPtr msg){  // コールバック関数
        RCLCPP_INFO( this->get_logger(), "Training:%s", msg->data.c_str() );
    }
private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;// Subscriberのポインタ
};
