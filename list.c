#include <stdlib.h>
#include "list.h"

Node* create_node(Task task) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->task = task;
    new_node->next = NULL;
    return new_node;
}

void insert_task(Node** head, Task task) {
    Node* new_node = create_node(task);
    if (*head == NULL || (*head)->task.deadline > task.deadline) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current->next != NULL && current->next->task.deadline <= task.deadline) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void delete_task(Node** head, int id) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->task.id == id) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->task.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

Node* get_earliest_deadline_task(Node** head) {
    if (*head == NULL) return NULL;
    Node* task_node = *head;
    *head = (*head)->next;
    return task_node;
}
