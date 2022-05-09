/**
 * Representation of a task in the system.
 */

#include <string>
#ifndef TASK_H
#define TASK_H

// representation of a task
typedef struct task {
    std::string name;
    //int tid; n�o sei o que �
    int priority;
    int burst;
} Task;

#endif
