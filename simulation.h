#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <queue>
#include "event.h"

class simulation {
    public:
        simulation();
        void run();
        void scheduleEvent(event* newEvent);
        unsigned int time;
    protected:
        std::priority_queue<event*,
            std::vector<event*, std::allocator<event*> >,
            eventComparator> eventQueue;
};

#endif

