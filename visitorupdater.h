#ifndef VISITORUPDATER_H
#define VISITORUPDATER_H

#include "Qt"
#include "QtCore"
#include "visitor.h"

class VisitorUpdater : public QObject
{
    Q_OBJECT
    QThread workerThread;

public slots:
    void doWork();

signals:
    void VisitorsUpdate(QVector<Visitor>* visitors);
};

#endif // VISITORUPDATER_H
