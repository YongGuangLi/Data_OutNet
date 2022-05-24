#include "outnetferry.h"

OutNetFerry::OutNetFerry(QObject *parent):QObject(parent)
{
    initMQTTConfig();

    if(SingleRedisHelp->connect())
        qDebug()<<"Redis Connect Sucess";


    QtConcurrent::run(this, &OutNetFerry::ferryTask);

    QtConcurrent::run(this, &OutNetFerry::watchRedisList);
}

OutNetFerry::~OutNetFerry()
{
    qDebug()<<"in1111111111111111";
}

bool OutNetFerry::initMQTTConfig()
{
    QFile file(qApp->applicationDirPath() + QDir::separator() + "MQTTConfig.xml");
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QDomDocument doc;
    if (!doc.setContent(&file))
    {
        file.close();
        return false;
    }
    file.close();

    QDomElement docElem = doc.documentElement();
    QDomNode n = docElem.firstChild();
    while (!n.isNull())
    {
        QDomElement e = n.toElement();
        if (!e.isNull())
        {
            QString id = e.attribute("id");
            QString serverURI = e.attribute("serverURI");
            QString clientId = e.attribute("clientId");
            QString userName = e.attribute("userName");
            QString passWord = e.attribute("passWord");
            QString pubTopic = e.attribute("pubTopic");
            QString subTopic = e.attribute("subTopic");

            if(mapMQTTClients_.contains(id))
                qWarning()<<"MQTT id exist:"<<id;
            else
            {
                MQTTSyncClient *client = new MQTTSyncClient(serverURI.toStdString(), clientId.toStdString(), pubTopic.toStdString(), subTopic.toStdString());
                addMQTTSyncClient(id, client);

                int result = client->connect(userName.toStdString(), passWord.toStdString());
                if(!result)
                    qDebug()<<"MQTT Connect Success:"<<serverURI;
            }
        }
        n = n.nextSibling();
    }
    return true;
}

QString OutNetFerry::JsonToString(QVariantMap jsonObject)
{
    bool ok;
    QJson::Serializer serializer;
    return QString(serializer.serialize(jsonObject, &ok));
}

QVariantMap OutNetFerry::RemotePointToJson(google::protobuf::RemotePoint remotePoint)
{
    QVariantMap jsonObject;
    google::protobuf::MessageType type = remotePoint.msgtype();
    switch (type)
    {
    case google::protobuf::MT_PointDPS:
    {
        google::protobuf::PointDPS pointDPS = remotePoint.pointdps();
        string deviceID = pointDPS.deviceid();
        jsonObject.insert("deviceID", QString::fromStdString(deviceID));
        string name = pointDPS.name();
        jsonObject.insert("name", QString::fromStdString(name));
        string timestamp = pointDPS.timestamp();
        jsonObject.insert("timestamp", QString::fromStdString(timestamp));
        float value = pointDPS.value();
        jsonObject.insert("value", value);
        break;
    }
    case google::protobuf::MT_PointMV:
    {
        google::protobuf::PointMV pointMV = remotePoint.pointmv();
        string deviceID = pointMV.deviceid();
        jsonObject.insert("deviceID", QString::fromStdString(deviceID));
        string name = pointMV.name();
        jsonObject.insert("name", QString::fromStdString(name));
        string timestamp = pointMV.timestamp();
        jsonObject.insert("timestamp", QString::fromStdString(timestamp));
        int value = pointMV.value();
        jsonObject.insert("value", value);
        break;
    }
    default:
        break;
    }
    return jsonObject;
}



void OutNetFerry::addMQTTSyncClient(QString id, MQTTSyncClient *client)
{
    mapMQTTClients_[id] = client;
}

void OutNetFerry::watchRedisList()
{
    while (true)
    {
        QMapIterator<QString, MQTTSyncClient*> it(mapMQTTClients_);
        while(it.hasNext())
        {
            it.next();
            QString id = it.key();
            MQTTSyncClient *client = it.value();

            while(SingleRedisHelp->llen(id.toStdString()))
            {
                QMutexLocker loker(&mutex_);
                if(client->isConnect())
                {
                    string payload;
                    if(SingleRedisHelp->brpop(id.toStdString(), payload))
                    {
                        qDebug()<<"payload:"<<payload.c_str();
                        client->publish(payload.c_str());
                    }
                }
                else if(client->connect() != 0)            //重连，如果重连失败退出循环
                    break;
            }
            sleep(1);
        }
    }
}

void OutNetFerry::ferryTask()
{
    FerryUtils ferryUtils;
    int rc = ferryUtils.openDevice();
    if (rc)
    {
        printf("open %d failure\n", rc);
        return;
    }
    else
        qDebug()<<"Open ferry Success";

    void *buf = calloc(1024, sizeof(char));
    while(1)
    {
        memset(buf, 0, 1024);
        size_t size = 0;
        rc = ferryUtils.ferryRecv(buf, &size);
        if(!rc)
        {
            google::protobuf::RemotePoint remotePoint;
            bool result = remotePoint.ParseFromArray(buf, size);
            if(result)
            {
                QVariantMap jsonObject = RemotePointToJson(remotePoint);
                QString payload = JsonToString(jsonObject);

                QMapIterator<QString, MQTTSyncClient*> it(mapMQTTClients_);
                while(it.hasNext())
                {
                    it.next();
                    QString id = it.key();
                    MQTTSyncClient *client = it.value();

                    QMutexLocker loker(&mutex_);
                    if(client->publish(payload.toStdString().c_str()))
                    {
                        qWarning()<<"MQTT Push Failure,Cache To Redis";
                        SingleRedisHelp->lpush(id.toStdString(), payload.toStdString());
                    }
                }
            }
        }
        else
            sleep(1);
    }
}



