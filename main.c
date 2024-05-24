#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "list.h"
#include "task.h"

void read_tasks_from_file(const char* filename, Node** head) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    int id, execution_time, period, deadline;
    while (fscanf(file, "%d %d %d %d", &id, &execution_time, &period, &deadline) != EOF) {
        Task task = {id, execution_time, period, deadline};
        add_task(head, task);
    }
    fclose(file);
}

int main() {
    Node* head = NULL;
    read_tasks_from_file("tasks.txt", &head);
    schedule(&head);
    return 0;
}
