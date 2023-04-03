#include "MessagePushServicer.h"
#include <string>
#include <unistd.h>
#include <pthread.h>
#define SERVER_ADDRESS "tcp://47.98.165.105:1883"
#define CLIENT_ID "ComClient-2"


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
    // 创建主题列表
    std::vector<std::string> topics{"Topic_1", "Topic_2", "Topic_3"};
    // 创建 ComServicer 对象
    ComService::MessagePushServicer mpsServicer(SERVER_ADDRESS, CLIENT_ID, pmessageQueue, topics);
    // 执行服务
    // mpsServicer.start();
    // 创建线程实时监听消息队列
    pthread_t pthread;
    pthread_create(&pthread, NULL, myThread, (void *)pmessageQueue);
    pthread_join(pthread, NULL);
    while(1){}
}