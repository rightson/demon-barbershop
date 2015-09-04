#include <stdio.h>
#include "barberShopSimulation.h"

barberShopSimulation::barberShopSimulation() :
    simulation(), 
    revenue(0),
    busy(false),
    busyStartTime(0),
    customers(0), 
    waitingCustomers(0),
    lostCustomers(0) {
}

bool barberShopSimulation::isFull() {
    return waitingCustomers >= QUEUE_SIZE;
}

void barberShopSimulation::loseCostomer() {
    lostCustomers++;
    printf("Lost %u customers totally\n", lostCustomers);
}

bool barberShopSimulation::canWait() {
    return waitingCustomers != 0 || busy;
}

void barberShopSimulation::wait() {
    waitingCustomers++;
    time += (waitingCustomers * SERVER_TIME_PER_CUSTOMER);
}

void barberShopSimulation::serve(unsigned int t) {
    ++customers;
    if (waitingCustomers) --waitingCustomers;
    busy = true;
    busyStartTime = t;
    printf("serve: totalCustomers=%u, waitingCustomers=%u, busy=%d, busyStartTime=%u\n", customers, waitingCustomers, busy, busyStartTime);
}

void barberShopSimulation::leave() {
    busy = false;
    revenue += PROFIT_PER_CUSTOMER;
    busyStartTime = time;
    printf("leave: totalCustomers=%u, waitingCustomers=%u, busy=%d, paid=%u, revenue=%.2f\n", customers, waitingCustomers, busy, PROFIT_PER_CUSTOMER, revenue);
}

double barberShopSimulation::getProfit() { 
    return revenue; 
}

unsigned int barberShopSimulation::getWaitTime() {
    unsigned currentCustomerTimeRequired = 2;
    if (busyStartTime < time) currentCustomerTimeRequired = (time - busyStartTime); 
    unsigned waitTime = time + currentCustomerTimeRequired + waitingCustomers * SERVER_TIME_PER_CUSTOMER;
    printf("calculating wait time=%u, busyStartTime=%u, currentServeTimeLeft=%u, waitingCustomers=%u\n", time, busyStartTime, (time-busyStartTime), waitingCustomers);
    return waitTime;
}

unsigned int barberShopSimulation::getCustomers() { 
    return customers; 
}

unsigned int barberShopSimulation::getLostCostomer() {
    return lostCustomers; 
}

