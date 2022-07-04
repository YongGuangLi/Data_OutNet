#include "outnetferry.h"

OutNetFerry::OutNetFerry(QObject *parent):QObject(parent)
{
    initMQTTConfig();

    QtConcurrent::run(this, &OutNetFerry::ferryTask);


    for(int i = 0; i < listMQTTClients_.size(); ++i)
    {
        MQTTAsyncClient* client = listMQTTClients_.at(i);
        QtConcurrent::run(this, &OutNetFerry::watchRedisList, client);
    }
}

OutNetFerry::~OutNetFerry()
{
}

bool OutNetFerry::initMQTTConfig()
{
    QFile file(qApp->applicationDirPath() + QDir::separator() + "MQTTConfig.xml");
    if (!file.open(QIODevice::ReadOnly))
    {
        qCritical()<<"MQTTConfig Read Failure";
        return false;
    }

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


            MQTTAsyncClient *client = new MQTTAsyncClient(id.toStdString() , serverURI.toStdString(), clientId.toStdString(), pubTopic.toStdString(), subTopic.toStdString());
            addMQTTAsyncClient(client);

            client->connect(userName.toStdString(), passWord.toStdString());
            sleep(1);

            client->subscribe(subTopic.toStdString());
            sleep(1);
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
        int value = pointDPS.value();
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
        float value = pointMV.value();
        jsonObject.insert("value", value);
        break;
    }
    default:
        break;
    }
    return jsonObject;
}



void OutNetFerry::addMQTTAsyncClient( MQTTAsyncClient *client)
{
    listMQTTClients_.push_back(client);
}

void OutNetFerry::watchRedisList(MQTTAsyncClient *client)
{
    string id = client->getId();
    while (true)
    {
        while(SingleRedisHelp->llen(id))
        {
            if(client->isConnect() == 0)
            {
                string payload;
                if(SingleRedisHelp->brpop(id, payload))
                {
                    qDebug()<<"Payload:"<<payload.c_str();
                    client->publish(payload.c_str());
                }
            }
            else
            {
                client->connect();
                break;
            }
        }
        sleep(1);
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
        //QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        //qDebug()<<1<<strDateTime;
        if(!rc)
        {
            google::protobuf::RemotePoint remotePoint;
            bool result = remotePoint.ParseFromArray(buf, size);
            if(result)
            {
                QVariantMap jsonObject = RemotePointToJson(remotePoint);
                QString payload = JsonToString(jsonObject);

                for(int i = 0; i < listMQTTClients_.size(); ++i)
                {
                    MQTTAsyncClient* client = listMQTTClients_.at(i);
                    string id = client->getId();

                    if(client->publish(payload.toStdString().c_str()) != 0)
                    {
                        qWarning()<<"MQTT Push Failure,Cache To Redis,ID:"<<id.c_str();
                        SingleRedisHelp->lpush(id, payload.toStdString());
                    }
                }
                qDebug()<<payload;
            }
            //QString strDateTime1 = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            //qDebug()<<2<<strDateTime1;
        }
        else
            usleep(1000);
    }
}



