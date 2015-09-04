#ifndef ARRIVAL_EVENT_H_
#define ARRIVAL_EVENT_H_

#include "event.h"

class arrivalEvent : public event {
    public:
        arrivalEvent(unsigned int arrivalTime); 
        virtual void processEvent();
    private:
        unsigned int size;
};

#endif

