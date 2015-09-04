#ifndef BARBER_SHOP_SIMULATION_H_
#define BARBER_SHOP_SIMULATION_H_

#include "simulation.h"

class barberShopSimulation : public simulation {
	public:
		barberShopSimulation();

        bool isFull();
        bool canWait();
        void loseCostomer();
		void wait();
        void serve(unsigned int);
		void leave();

        double getProfit();
        unsigned int getWaitTime();

        unsigned int getCustomers();
        unsigned int getLostCostomer();

        enum { 
            QUEUE_SIZE = 3, 
            SERVER_TIME_PER_CUSTOMER = 2,
            PROFIT_PER_CUSTOMER = 300
        };

	private:
		double revenue;
        bool busy;
        unsigned int busyStartTime;
		unsigned int customers;
        unsigned int waitingCustomers;
        unsigned int lostCustomers;
};

extern barberShopSimulation barberShop;

#endif

