#ifndef LEAVE_EVENT_H_
#define LEAVE_EVENT_H_

#include "event.h"

class leaveEvent : public event {
    public:
        leaveEvent(unsigned int leaveTime); 
        virtual void processEvent();
    private:
        unsigned int size;
};

#endif

