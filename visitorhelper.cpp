#include "visitorhelper.h"
#include <QVector>
#include "visitor.h"

VisitorHelper::VisitorHelper()
{
   // VisitorHelper::_instance = new VisitorHelper();
}

QVector<Visitor>* VisitorHelper::Items(){
    static QVector<Visitor>* visitors = new QVector<Visitor>();
    return visitors;
}

void VisitorHelper::Initialize(){

}
