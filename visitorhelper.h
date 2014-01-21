#ifndef VISITORHELPER_H
#define VISITORHELPER_H

#include "visitor.h"

class VisitorHelper
{
public:
    static QVector<Visitor>* Items();

    static VisitorHelper* Instance(){
        static VisitorHelper instance;
        return &instance;
    }

    void Initialize();


private:
    VisitorHelper();
    VisitorHelper(const VisitorHelper& root);
    VisitorHelper& operator=(const VisitorHelper&);

};

#endif // VISITORHELPER_H
