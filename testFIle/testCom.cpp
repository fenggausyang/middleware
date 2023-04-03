#include "ComServicer.h"
#include <string>
#include <unistd.h>
#include <pthread.h>
#define SERVER_ADDRESS "tcp://47.98.165.105:1883"
#define CLIENT_ID "ComClient-1"


void * myThread(void * arg) {
    std::queue<std::pair<std::string, std::string>> * messageQueue = (std::queue<std::pair<std::string, std::string>> *)arg;
    std::cout << "pthread Start" << std::endl;
    while(1){
        if(!messageQueue->empty()){
            std::cout << "Message arrived" << std::endl;
            std::cout << "Topic: " << messageQueue->front().first << std::endl;
            std::cout << "Message: " << messageQueue->front().second << std::endl;
            messageQueue->pop();
        }
    }
}
int main() {
    // 创建消息队列，返回
    std::queue<std::pair<std::string, std::string>> * pmessageQueue = new std::queue<std::pair<std::string, std::string>>();
    // 创建 ComServicer 对象
    ComService::ComServicer comService(SERVER_ADDRESS, CLIENT_ID, pmessageQueue);
    // 连接服务器
    comService.connect();


    // 订阅主题 Topic_1
    // comService.addTopic("Topic_1");
    // 订阅主题 Topic_2
    // comService.addTopic("Topic_2");


    // 测试订阅主题组
    std::vector<std::string> topics{"Topic_1", "Topic_2", "Topic_3"};
    comService.addTopics(topics);
    std::vector<std::string> mytopics = comService.getTopics();
    for(auto topic : mytopics){
        std::cout << topic << std::endl;
    }

    // 测试取消订阅主题
    // comService.subTopic("Topic_3");



    // 创建线程实时监听消息队列
    pthread_t pthread;
    pthread_create(&pthread, NULL, myThread, (void *)pmessageQueue);
    pthread_join(pthread, NULL);
    while(1){}
}