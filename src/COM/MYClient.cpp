#include "MYClient.h"

void MYClient::connect() {
    // 设置连接选项
    mqtt::connect_options connOpts;
    // 在 MQTT 协议中，客户端和服务器之间的连接通常需要保持活动状态，以确保消息传递的可靠性。保持活动状态是通过定期发送一个称为 "Keep-Alive" 的控制包来实现的。Keep-Alive 控制包是一个简单的空消息，其目的是告诉服务器客户端仍然处于活动状态。
    // 在 MQTT 库中，set_keep_alive_interval 方法用于设置客户端发送 Keep-Alive 控制包的时间间隔。这个时间间隔通常是以秒为单位指定的，表示客户端在多长时间内需要发送一个 Keep-Alive 控制包。如果客户端在指定的时间间隔内没有发送任何消息，则服务器可能会认为客户端已经断开连接，并且将其视为离线状态。
    // 通过设置适当的 Keep-Alive 时间间隔，可以确保客户端和服务器之间的连接保持活动状态，并防止连接中断或超时。
    connOpts.set_keep_alive_interval(20);
    // 在 MQTT 协议中，客户端可以选择是保留会话状态（persistent session）还是清除会话状态（clean session）来与服务器建立连接。如果客户端选择保留会话状态，那么客户端与服务器之间的所有消息和订阅关系都会被保留下来，并在断开连接后恢复。如果客户端选择清除会话状态，那么客户端与服务器之间的所有消息和订阅关系都会被删除，断开连接后不会恢复。
    // 在 MQTT 库中，set_clean_session 方法用于设置客户端是否使用清除会话状态。如果将其设置为 True，表示使用清除会话状态，否则表示使用保留会话状态。这个方法一般在客户端连接到 MQTT 服务器之前设置，以确保客户端和服务器之间建立连接时会使用正确的会话状态。
    // 如果客户端希望在断开连接后恢复其消息和订阅关系，应该选择保留会话状态。如果客户端只关心当前连接的消息和订阅关系，可以选择清除会话状态。但是需要注意的是，使用清除会话状态可能会导致客户端在断开连接后丢失一些重要的消息或订阅关系，因此需要根据具体的使用场景来进行选择
    connOpts.set_clean_session(true);
    try {
        std::cout << "Connecting to the MQTT server..." << std::flush;
        // 连接MQTT服务器
        client.connect(connOpts)->wait();
        std::cout << "OK" << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "\nERROR: Unable to connect to MQTT server: " << exc.what() << std::endl;
        exit(1);
    }
}
// 订阅主题
void MYClient::subscribe() {
    topic.subscribe();
}
// 运行客户端
void MYClient::run() {
    while (true) {}
}
