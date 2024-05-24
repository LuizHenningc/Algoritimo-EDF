#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"
#include "list.h"

void add_task(Node** head, Task task);
void schedule(Node** head);

#endif
