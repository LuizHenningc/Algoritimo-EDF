#include "scheduler.h"
#include "cpu.h"
#include <stddef.h>
#include <stdlib.h>

void add_task(Node** head, Task task) {
    insert_task(head, task);
}

void schedule(Node** head) {
    while (*head != NULL) {
        Node* task_node = get_earliest_deadline_task(head);
        if (task_node != NULL) {
            execute_task(task_node->task);
            free(task_node);
        }
    }
}
