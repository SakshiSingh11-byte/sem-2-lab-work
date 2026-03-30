#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = val;
    t->next = NULL;
    if (rear == NULL) {
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;}}

int dequeue() {
    if (front == NULL) {
        printf("Queue Empty\n");
        return -1;}
    struct node *t = front;
    int val = t->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(t);
    return val;}

void display() {
    struct node *p = front;
    if (p == NULL) {
        printf("Empty\n");
        return;}
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;}
    printf("\n");}

int main() {
    int choice, val;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
        } else if (choice == 2) {
            val = dequeue();
            if (val != -1) printf("Dequeued: %d\n", val);
        } else if (choice == 3) {
            display();
        } else {
            exit(0);}}
    return 0;}
