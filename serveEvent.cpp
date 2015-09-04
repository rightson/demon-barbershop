#include <stdio.h>
#include "serveEvent.h"
#include "leaveEvent.h"
#include "barberShopSimulation.h"

class leaveEvent;

serveEvent::serveEvent(unsigned int t)
    : event(t, NORMAL) {
}

void serveEvent::processEvent() {
    printf(">>> Process serve event\n");
    unsigned int leaveTime = incrementTime(barberShop.SERVER_TIME_PER_CUSTOMER);
    barberShop.scheduleEvent(new leaveEvent(leaveTime));
    printf("scheduling: customer will leave at Time = %u\n", leaveTime);
    barberShop.serve(barberShop.time);
}

