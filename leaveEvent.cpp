#include "leaveEvent.h"
#include "barberShopSimulation.h"

leaveEvent::leaveEvent (unsigned int leaveTime) 
    : event(leaveTime, HIGH) {
}

void leaveEvent::processEvent() {
    printf(">>> Process leave event\n");
    barberShop.leave();
}

