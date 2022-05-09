#include <string>
#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void add(std::string name, int priority, int burst);

// invoke the scheduler
void schedule();
