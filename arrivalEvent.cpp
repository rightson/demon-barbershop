#include <stdio.h>
#include "arrivalEvent.h"
#include "serveEvent.h"
#include "leaveEvent.h"
#include "barberShopSimulation.h"

arrivalEvent::arrivalEvent (unsigned int arrivalTime) 
    : event(arrivalTime, LOW) {
}

void arrivalEvent::processEvent() {
    printf(">>> Process arrival event: ");
    if (barberShop.isFull()) {
        printf("shop is full\n");
        barberShop.loseCostomer();
    }
    else if (barberShop.canWait()) {
        printf("customer need to wait\n");
        unsigned int waitTime = barberShop.getWaitTime();
        barberShop.scheduleEvent(new serveEvent(waitTime));
        printf("scheduling: customer will be served at Time %u\n", waitTime);
        barberShop.wait();
    }
    else {
        printf("customer can be served immediately\n");
        unsigned int serveTime = incrementTime(barberShop.SERVER_TIME_PER_CUSTOMER);
        barberShop.scheduleEvent(new leaveEvent(serveTime));
        printf("scheduling: customer will leave at Time %u\n", serveTime);
        barberShop.serve(barberShop.time);
    }
}

