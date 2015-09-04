#include "event.h"

event::event(unsigned int t, unsigned int p) 
    : time(t),
	  priority(p) { 
}

event::~event() {
}

unsigned int event::incrementTime(unsigned int t) {
    return time + t;
}

