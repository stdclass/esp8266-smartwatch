#ifndef _BASECONTROLLER_H
#define _BASECONTROLLER_H

#include "SimpleList.h"

class BaseController
{
    public:
        virtual void render() = 0;
        virtual void buttonSelect(SimpleList<BaseController *> *controllers) = 0;
        virtual void buttonDown() = 0;
        virtual void buttonUp() = 0;
        virtual ~BaseController() {}
};

#endif // _BASECONTROLLER_H
