#include <QCoreApplication>
#include "outnetferry.h"

// 加锁
QMutex mutex;

void outputMessage(QtMsgType type, const char *msg)
{
	QString text;
	switch(type) {
	case QtDebugMsg:
		text = QString("Debug: ");
		break;
	case QtWarningMsg:
		text = QString("Warning: ");
		break;
	case QtCriticalMsg:
		text = QString("Critical:");
		break;
	case QtFatalMsg:
		text = QString("Fatal: ");
		break;
	default:
		text = QString("Debug: ");
	}

	// 设置输出信息格式 
	QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString strMessage = QString("%1 %2 %3 ").arg(text).arg(strDateTime).arg(msg);

    // 输出信息至文件中（读写、追加形式）
    QMutexLocker locker(&mutex);
    QFile file(QString("./%1log.txt").arg(QDateTime::currentDateTime().toString("yyyyMMddhhmm")));
	file.open(QIODevice::ReadWrite | QIODevice::Append);
	QTextStream stream(&file);
	stream << strMessage << "\r\n";
	file.flush();
    file.close();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); 

	qInstallMsgHandler(outputMessage); 
	
    if(SingleRedisHelp->connect("192.168.13.64"))
        qDebug()<<"Redis Connect Sucess";
    else
    {
        qCritical()<<"Redis Connect Failure";
        return -1;
    }

    OutNetFerry *outNetFerry = new OutNetFerry();

    return a.exec();
}
