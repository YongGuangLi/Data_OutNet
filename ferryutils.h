#ifndef FERRYUTILS_H
#define FERRYUTILS_H


#include <QMutexLocker>
#include <yyapi.h>
#include <stdio.h>
#include <unistd.h>


class FerryUtils
{
public:
    FerryUtils();
    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     打开隔离卡设备
    */
    int openDevice();

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     关闭隔离卡设备
    */
    void closeDevice();

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     接受数据
    */
    int ferryRecv(void *buf, size_t *count);

    /**
    * @date      2022-04-24
    * @param
    * @return
    * @brief     发送数据
    */
    int ferrySend(void *buf, size_t count);
private:
    void *dev;
     int chan ;
     int virt_chan;
};

#endif // FERRYUTILS_H
