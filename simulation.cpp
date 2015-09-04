#include "simulation.h"

simulation::simulation() 
    : time(0),
      eventQueue() {
}

void simulation::scheduleEvent(event* newEvent) {
    eventQueue.push(newEvent);
}

void simulation::run() {
    while (!eventQueue.empty()) {
        event* nextEvent = eventQueue.top();
        eventQueue.pop();
        time = nextEvent->time;
		printf("\nTIME = %u\n", time);
        nextEvent->processEvent();
        delete nextEvent;
    }
}

