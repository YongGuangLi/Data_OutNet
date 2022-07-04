#include "ferryutils.h"

FerryUtils::FerryUtils()
{

}

int FerryUtils::openDevice()
{
    int rc = yy_ferry_open(&dev, &chan, &virt_chan);
    printf("rc = %d Total chan %d, virt_chan %d, %p\n", rc, chan, virt_chan, dev);
    return rc;
}

void FerryUtils::closeDevice()
{
    yy_ferry_close(&dev);
}

int FerryUtils::ferryRecv(void *buf, size_t *count)
{
    if (!buf)
        return -1;

    int rc = yy_ferry_recv(dev, 0, virt_chan, buf, count);
    return rc;
}

int FerryUtils::ferrySend(void *buf, size_t count)
{
    return yy_ferry_send(dev, 0, virt_chan, buf, count);
}
