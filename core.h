#ifndef CORE_H
#define CORE_H

#include "visitorhelper.h"
#include "connectionhelper.h"

class Core
{
public:
    Core();

    static VisitorHelper* Visitors();

    static ConnectionHelper* Connection();
};

#endif // CORE_H
