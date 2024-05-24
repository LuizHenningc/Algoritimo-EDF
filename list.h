#ifndef LIST_H
#define LIST_H

#include "task.h"

typedef struct Node {
    Task task;
    struct Node* next;
} Node;

Node* create_node(Task task);
void insert_task(Node** head, Task task);
void delete_task(Node** head, int id);
Node* get_earliest_deadline_task(Node** head);

#endif
