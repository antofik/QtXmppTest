#include "core.h"
#include "visitorhelper.h"
#include "connectionhelper.h"

Core::Core(){}
VisitorHelper* Core::Visitors(){    return VisitorHelper::Instance();}
ConnectionHelper* Core::Connection(){return ConnectionHelper::Instance();}
