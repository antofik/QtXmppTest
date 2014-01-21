#include "visitor.h"
#include <QtGlobal>
#include <QtCore>

Visitor::Visitor()
{
    int n = qrand() % ((100000000) - 10000000) + 10000000;
    this->Id = "#" + QString::number(n);
    this->Name = QUuid::createUuid().toString();
}

Visitor::~Visitor(){

}
