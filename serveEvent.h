#ifndef SERVE_EVENT_H_
#define SERVE_EVENT_H_

#include "event.h"

class serveEvent : public event {
    public:
        serveEvent (unsigned int t); 
        virtual void processEvent();
};

#endif

