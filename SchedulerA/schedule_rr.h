#include <iostream>


#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

void iniciar();
// add a task to the list 
void add(std::string name, int tid, int priority, int burst);

// invoke the scheduler
void schedule();
