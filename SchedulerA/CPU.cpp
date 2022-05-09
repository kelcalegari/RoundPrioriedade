/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <iostream>

#include "task.h"

// run this task for the specified time slice
void run(Task task, int slice) {
    std::cout << "\n Running task = nome: " << task.name << " - priority: " << task.priority << " - burst: " << task.burst << " - slice: " << slice;
}
