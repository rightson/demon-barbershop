# des-barbershop
des-barbershop is a barbershop simulator used to demonstrate how a discrete-event simulation works. "des" is the abbrivation of discrete-event simulation. 

# Introduction
A discrete-event simulation is usually composed of three data structures:
- state variable
- event list
- global clock variable

There is only one barber in the barbershop. The state variables is the state of barber and customers. The barber can be "busy" (i.e. serving a customer) or not. The customers can be waiting, be served, leaving, or just abandom.

There are three type of events: arrival, serve, and leave event, a STL priority queue is used to maintain these events. The events is sorted by time stamp. In the same time stamps, the event will be sorted by the event category: leaving (high priority), serving (normal priority), and arrival (low priority).

We use a integer to describe the time, each event will be invoked in a integer-based time stamp.

# Others
Any feedback or modification is welcome!
