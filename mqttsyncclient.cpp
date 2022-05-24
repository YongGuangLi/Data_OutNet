#include "mqttsyncclient.h"


#define QOS         1
#define TIMEOUT     10000L



void delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
    MQTTSyncClient *client = static_cast<MQTTSyncClient *>(context);
    client->setDeliveredtoken(dt);
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: %.*s\n", message->payloadlen, (char*)message->payload);
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause)
{
    MQTTSyncClient *client = static_cast<MQTTSyncClient *>(context);
    printf("\nConnection lost:%s\n", client->getServerURI().c_str());
    client->setConnectStatus(false);
}



MQTTSyncClient::MQTTSyncClient(string serverURI, string clientId, string pubTopic, string subTopic, int cleansession)
    :client_(NULL)
{
    cleansession_ = cleansession;
    pubTopic_ = pubTopic;
    subTopic_ = subTopic;
    serverURI_ = serverURI;
    isConnect_ = false;
    int rc;
    if ((rc = MQTTClient_create(&client_, serverURI.c_str(), clientId.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to create client object, return code %d\n", rc);
    }

    if ((rc = MQTTClient_setCallbacks(client_, (void *)this, connlost, msgarrvd, delivered)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to set callback, return code %d\n", rc);
    }
}


MQTTSyncClient::~MQTTSyncClient()
{
    MQTTClient_destroy(&client_);
}

int MQTTSyncClient::connect(string username, string password)
{
    userName_ = username;
    passWord_ = password;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = cleansession_;
    conn_opts.username = username.c_str();
    conn_opts.password = password.c_str();

    int rc = MQTTClient_connect(client_, &conn_opts);
    if (rc != MQTTCLIENT_SUCCESS)
        printf("Failed to connect, return code %d\n", rc);
    else
        isConnect_ = true;

    return rc;
}

int MQTTSyncClient::connect()
{
    return connect(userName_, passWord_);
}

bool MQTTSyncClient::isConnect()
{
    return isConnect_;
}


int MQTTSyncClient::disConnect()
{
    int rc = MQTTClient_disconnect(client_, 10000);
    if (rc != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to disconnect, return code %d\n", rc);
    }
    isConnect_ = false;
    return rc;
}


int MQTTSyncClient::publish(string topic, const char* payload, int qos, int retained)
{
    if(!isConnect_)
        return -1;

    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    pubmsg.payload = (void *)payload;
    pubmsg.payloadlen = (int)strlen(payload);
    pubmsg.qos = qos;
    pubmsg.retained = retained;
    deliveredtoken_ = 0;
    MQTTClient_deliveryToken token;

    int rc = MQTTClient_publishMessage(client_, topic.c_str(), &pubmsg, &token);

    if (rc != MQTTCLIENT_SUCCESS)
        printf("Failed to publish message:%s, return code %d\n", serverURI_.c_str(), rc);
    else
    {
        printf("Waiting for publication of %s on topic %s \n", payload, topic.c_str());
        while (deliveredtoken_ != token)
        {
#if defined(_WIN32)
            Sleep(100);
#else
            usleep(10000L);
#endif
            if(!isConnect_)
                return -1;
        }
    }
    return rc;
}

int MQTTSyncClient::publish(const char *payload, int qos, int retained)
{
    return publish(pubTopic_, payload, qos, retained);
}

int MQTTSyncClient::subscribe(string topic, int qos)
{
    int rc = MQTTClient_subscribe(client_, topic.c_str(), qos);
    if(rc != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to subscribe, return code %d\n", rc);
    }
    return rc;
}


void MQTTSyncClient::setConnectStatus(bool status)
{
    isConnect_ = status;
}


string MQTTSyncClient::getServerURI() const
{
    return serverURI_;
}

void MQTTSyncClient::setDeliveredtoken(MQTTClient_deliveryToken deliveredtoken)
{
    deliveredtoken_ = deliveredtoken;
}
