#include "visitorupdater.h"
#include "QtCore"
#include "QXmppClient.h"
#include "core.h"
#include "Qt"

void VisitorUpdater::doWork()
{
    QXmppClient* client = Core::Connection()->client;
    while(1==1){
        qDebug() << "loop";
        QThread::sleep(0.5);
        try{
            qDebug() << "sending packet";
            QXmppIq iq;
            QXmppElement element;
            element.setTagName("query");
            element.setAttribute("xmlns", "consultant:visitorlist");
            iq.setExtensions(QXmppElementList() << element);
            client->sendPacket(iq);
            qDebug() << "waiting...";
            QThread::sleep(3);
            qDebug() << "next loop";
        } catch (const std::exception& ex) {
            qDebug() << "VisitorUpdater Error";
            //qDebug() << "VisitorUpdater Error: " << ex;
        } catch (const std::string& ex) {
            qDebug() << "VisitorUpdater Error";
           //qDebug() << "VisitorUpdater Error: " << ex;
        }catch(...){
            qDebug() << "VisitorUpdater Error";
        }

    }
}
