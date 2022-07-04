#ifndef OUTNETFERRY_H
#define OUTNETFERRY_H

#include <QCoreApplication>
#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QDomElement>
#include <QFile>
#include <QDir>
#include <QThreadPool>
#include <QMap>
#include <QJson/Parser>
#include <QJson/Serializer>
#include <QMapIterator>
#include <QtCore>
#include "RedisHelper.h"
#include "mqttasyncclient.h"
#include "ferryutils.h"
#include "RemotePoint.pb.h"

class OutNetFerry : public QObject
{
    Q_OBJECT
public:
    explicit OutNetFerry(QObject *parent = 0);
    ~OutNetFerry();
    /**
    * @date      2022-04-26
    * @param
    * @return
    * @brief     从xml文件中读取MQTT云平台配置信息
   */
    bool initMQTTConfig();

    /**
    * @date      2022-05-06
    * @param
    * @return
    * @brief     json对象转成string
    */
    QString JsonToString(QVariantMap jsonObject);

    /**
    * @date      2022-05-07
    * @param
    * @return
    * @brief    RemotePoint对象转成Json
    */
    QVariantMap RemotePointToJson(google::protobuf::RemotePoint remotePoint);

    /**
    * @date      2022-04-26
    * @param
    * @return
    * @brief     保存MQTT连接客户端
   */
    void addMQTTAsyncClient(MQTTAsyncClient*client);

    /**
    * @date      2022-04-26
    * @param
    * @return
    * @brief     监视redis中的链表，如有数据则发布到MQTT云平台
   */
    void watchRedisList(MQTTAsyncClient *client);

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     开启隔离卡接收数据,并发送到MQTT云平台，发送失败则缓存到redis中的链表
   */
    void ferryTask();

signals:

public slots:

private:
    QList<MQTTAsyncClient*> listMQTTClients_;
};

#endif // OUTNETFERRY_H
