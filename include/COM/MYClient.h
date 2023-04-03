#include <iostream>
#include <cstring>
#include "mqtt/async_client.h"
class MYClient {
public:
    // 构造函数， 初始化服务器地址、客户端ID、主题
    MYClient(const std::string& server_address, const std::string& client_id, const std::string& topic) :
        SERVER_ADDRESS(server_address), CLIENT_ID(client_id), TOPIC(topic), client(server_address, client_id), topic(client, topic, 1) {}
    // 连接MQTT服务器
    void connect();
    // 订阅主题
    void subscribe();
    // 运行MQTT客户端
    void run();
    // 设置回调函数
    void set_callback(mqtt::callback& cb) {
        client.set_callback(cb);
    }
private:
    const std::string SERVER_ADDRESS; // 服务器地址
    const std::string CLIENT_ID; // 客户端ID
    const std::string TOPIC; // 主题
    mqtt::async_client client; // MQTT异步客户端
    mqtt::topic topic; // MQTT主题
};