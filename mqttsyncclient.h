#ifndef MQTTSYNCCLIENT_H
#define MQTTSYNCCLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include "MQTTClient.h"

using namespace std;

class MQTTSyncClient
{
public:
    MQTTSyncClient(string serverURI, string clientId, string pubTopic,string subTopic, int cleansession = 1);
    ~MQTTSyncClient();

    /**
    * @date      2022-04-24
    * @param
    * @return    0 | 0x00连接已接受 | 连接已被服务端接受 |
                 1 | 0x01连接已拒绝，不支持的协议版本 | 服务端不支持客户端请求的MQTT协议级别 |
                 2 | 0x02连接已拒绝，不合格的客户端标识符 | 客户端标识符是正确的UTF-8编码，但服务端不允许使用 |
                 3 | 0x03连接已拒绝，服务端不可用 | 网络连接已建立，但MQTT服务不可用 |
                 4 | 0x04连接已拒绝，无效的用户名或密码 | 用户名或密码的数据格式无效 |
                 5 | 0x05连接已拒绝，未授权 | 客户端未被授权连接到此服务器 |
    * @brief     连接MQTT云平台
    */
    int connect(string username, string password);

    int connect();

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     连接状态
    */
    bool isConnect();

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     断开连接
    */
    int disConnect();

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     发布消息
    */
    int publish(string topic, const char* payload,int qos = 1, int retained = 0);

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     发布消息
    */
    int publish(const char* payload,int qos = 1, int retained = 0);

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     订阅消息
    */
    int subscribe(string topic, int qos = 1);

public:
    void setConnectStatus(bool status);

    string getServerURI() const;

    void setDeliveredtoken(MQTTClient_deliveryToken deliveredtoken);
private:
    MQTTClient client_;
    int cleansession_;
    int stationVersion_;
    string serverURI_;
    string userName_;
    string passWord_;
    string pubTopic_;
    string subTopic_;
    bool isConnect_;
    MQTTClient_deliveryToken deliveredtoken_;
};

#endif // MQTTSYNCCLIENT_H
