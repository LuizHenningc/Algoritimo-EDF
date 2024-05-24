#include <stdio.h>
#include "cpu.h"

void execute_task(Task task) {
    printf("Executing task ID: %d, Execution Time: %d, Deadline: %d\n", task.id, task.execution_time, task.deadline);
}
