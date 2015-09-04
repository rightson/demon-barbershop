#ifndef EVENT_H_
#define EVENT_H_

enum { 
	LOW = 0,
	NORMAL = 1,	
	HIGH = 2
};

class event {
    public:
        event(unsigned int time, unsigned int priority = NORMAL);
		virtual ~event();
        virtual void processEvent () = 0;
        unsigned int incrementTime(unsigned int t);
        unsigned int time;
		unsigned int priority;
};

struct eventComparator {
    bool operator() (const event* left, const event* right) const {
		if (left->time == right->time) return (left->priority < right->priority);
        return left->time > right->time;
    }
};

#endif

