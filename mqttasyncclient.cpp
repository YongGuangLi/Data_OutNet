#include "mqttasyncclient.h"




void onDisconnectFailure(void* context, MQTTAsync_failureData* response)
{
    printf("Disconnect failed\n");
    MQTTAsyncClient *client = static_cast<MQTTAsyncClient *>(context);
    client->setConnected(1);
}

void onDisconnect(void* context, MQTTAsync_successData* response)
{
    printf("Successful disconnection\n");
    MQTTAsyncClient *client = static_cast<MQTTAsyncClient *>(context);
    client->setConnected(1);
}

void onSendFailure(void* context, MQTTAsync_failureData* response)
{
    //printf("Message send failed token %d error code %d message %s\n", response->token, response->code, response->message);
}

void onSend(void* context, MQTTAsync_successData* response)
{
    //printf("Message with token value %d delivery confirmed\n", response->token);
}


void onConnectFailure(void* context, MQTTAsync_failureData* response)
{
    printf("Connect failed, rc %d\n", response ? response->code : 0);
    MQTTAsyncClient *client = static_cast<MQTTAsyncClient *>(context);
    client->setConnected(1);
}


void onConnect(void* context, MQTTAsync_successData* response)
{
    printf("onConnect Success\n");
    MQTTAsyncClient *client = static_cast<MQTTAsyncClient *>(context);
    client->setConnected(0);
}

int messageArrived(void* context, char* topicName, int topicLen, MQTTAsync_message* m)
{
    /* not expecting any messages */
    return 1;
}

void onSubscribe(void* context, MQTTAsync_successData* response)
{
    printf("Subscribe succeeded\n");
}

void onSubscribeFailure(void* context, MQTTAsync_failureData* response)
{
    printf("Subscribe failed, rc %d\n", response->code);
}

void connlost(void *context, char *cause)
{
    MQTTAsyncClient *client = static_cast<MQTTAsyncClient *>(context);
    client->setConnected(1);
}


MQTTAsyncClient::MQTTAsyncClient(string id, string serverURI, string clientId, string pubTopic, string subTopic, int cleansession)
    :client_(NULL),isConnected_(1)
{
    cleansession_ = cleansession;
    id_ = id;
    pubTopic_ = pubTopic;
    subTopic_ = subTopic;
    serverURI_ = serverURI;

    int rc;
    if ((rc = MQTTAsync_create(&client_, serverURI.c_str(), clientId.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to create client object, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }

    if ((rc = MQTTAsync_setCallbacks(client_, (void *)this, connlost, messageArrived, NULL)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to set callback, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
}


MQTTAsyncClient::~MQTTAsyncClient()
{
    MQTTAsync_destroy(&client_);
}

int MQTTAsyncClient::connect(string username, string password)
{
    userName_ = username;
    passWord_ = password;

    MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.onSuccess = onConnect;
    conn_opts.onFailure = onConnectFailure;
    conn_opts.context = this;

    int rc;
    if ((rc = MQTTAsync_connect(client_, &conn_opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start connect, return code %d\n", rc);
    }

    return rc;
}

int MQTTAsyncClient::connect()
{
    return connect(userName_, passWord_);
}

int MQTTAsyncClient::isConnect()
{
    QMutexLocker locker(&mutex_);
    return isConnected_;
}


void MQTTAsyncClient::setConnected(int isConnected)
{
    QMutexLocker locker(&mutex_);
    isConnected_ = isConnected;
}


int MQTTAsyncClient::publish(const char *payload, int qos, int retained)
{
    return publish(pubTopic_, payload, qos, retained);
}


int MQTTAsyncClient::publish(string topic, const char* payload, int qos, int retained)
{
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    MQTTAsync_responseOptions pub_opts = MQTTAsync_responseOptions_initializer;

    pub_opts.onSuccess = onSend;
    pub_opts.onFailure = onSendFailure;
    pub_opts.context = client_;

    pubmsg.payload = (void *)payload;
    pubmsg.payloadlen = (int)strlen(payload);
    pubmsg.qos = qos;
    pubmsg.retained = retained;

    QMutexLocker locker(&mutex_);
    if(isConnected_)
        return -1;

    int rc;
    if ((rc = MQTTAsync_sendMessage(client_, topic.c_str(), &pubmsg, &pub_opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start sendMessage, return code %d\n ", rc);
    }

    return rc;
}


int MQTTAsyncClient::subscribe(string topic, int qos)
{
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    opts.onSuccess = onSubscribe;
    opts.onFailure = onSubscribeFailure;
    opts.context = client_;

    int rc;
    if ((rc = MQTTAsync_subscribe(client_, topic.c_str(), qos, &opts)) != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start subscribe, return code %d\n", rc);
    }
    return rc;
}


string MQTTAsyncClient::getId() const
{
    return id_;
}

string MQTTAsyncClient::getServerURI() const
{
    return serverURI_;
}
