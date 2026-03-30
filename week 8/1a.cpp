#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int q[MAX];
int front = -1;
int rear = -1;

void qinsert(int item) {
    if (rear == MAX - 1) {
        printf("\nLinear Queue Full - Insertion not possible\n");
        return;}
    if (rear == -1) {
        front = 0;
        rear = 0;} 
    else {
        rear = rear + 1;}
    q[rear] = item;
    printf("Inserted: %d\n", item);}

void qdelete() {
    if (front == -1) {
        printf("\nQueue Empty - Deletion not possible\n");
        return;}
    int item = q[front];
    if (front == rear) {
        front = -1;
        rear = -1;} 
    else {
        front = front + 1;}
	printf("Deleted item: %d\n", item);}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return;}
    printf("\nCurrent Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("[%d] ", q[i]);}
    printf("\nFront: %d, Rear: %d\n", front, rear);}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                qinsert(value);
                break;
            case 2:
                qdelete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");}}
    return 0;}
