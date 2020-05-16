# ros2_training

ros2_trainingは[ROSではじめるホビーロボット番外編](https://koso2-dan.booth.pm/items/2026421)で紹介する[ros2arduino](https://github.com/ROBOTIS-GIT/ros2arduino)とM5StackでROS2の学習を行うためのサンプルコードです。

## 動作環境
ROS2 Dashing Diademata  
Ubuntu 18.04  

## インストール方法
ROS2のワークスペースにcloneしてbuildすることで使用できます。

```
$ mkdir -p ~/ros2_ws/src
$ cd ~/ros2_ws/src
~/ros2_ws/src$ git clone https://github.com/nomumu/ros2_training.git
~/ros2_ws/src$ cd ..
~/ros2_ws$ colcon build
　〜ビルド成功した後〜
~/ros2_ws$ source install/setup.bash
```

## 作成される実行ファイルと実行方法
- hello_world  
ROS2のパッケージ生成コマンド`ros2 pkg create`の出力例です。  
`ros2 run ros2_training hello_world`  
- my_pub1  
ROS2のPublisherの作成例です。  
`ros2 run ros2_training my_pub1`  
- my_sub  
ROS2のSubscriberの作成例です。  
`ros2 run ros2_training my_sub`  
- my_sub_exec  
ROS2のExecutorの作成例です。  
`ros2 run ros2_training my_sub_exec`  
