#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "barberShopSimulation.h"
#include "arrivalEvent.h"

barberShopSimulation barberShop;

long randnum(int max) {
    return rand() % max;
}

void scheduleRandomEvents(bool random = true) {
    if (random) srand(time(NULL));
    for (unsigned t = 0; t < 20; t += randnum(6)) {
        barberShop.scheduleEvent(new arrivalEvent(t));
        printf("scheduling random arrival events: %u\n", t);
    }
}

int main(int argc, char* argv[]) {
    bool random = true;
    if (argc == 2) random = atoi(argv[1]);
    scheduleRandomEvents(random);
    barberShop.run();
    return 0;
}

