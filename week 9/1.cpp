#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct {
    int q[N];
    int front, rear;
} cqueue;

int isempty(int f) {
    return (f == -1);}

void cqinsert(cqueue *p, int item) {
    if ((p->front == 0 && p->rear == N - 1) || (p->rear + 1 == p->front)) {
        printf("\nCircular Queue Overflow\n");
        return;}
    
    if (p->front == -1) {
        p->front = p->rear = 0;
    } else {
        p->rear = (p->rear + 1) % N;}  
    p->q[p->rear] = item;}

int cqdelete(cqueue *p) {
    int item = p->q[p->front];
    if (p->front == p->rear) {
        p->front = p->rear = -1;
    } else {
        p->front = (p->front + 1) % N;}
    return item;}

void traversal(cqueue cq) {
    if (cq.front == -1) {
        printf("\nCircular Queue empty\n");
        return;}
    
    printf("\nContents of Circular Queue: ");
    int i = cq.front;
    while (1) {
        printf("%d ", cq.q[i]);
        if (i == cq.rear) break;
        i = (i + 1) % N;}
    printf("\n");}

int main() {
    int choice, item;
    cqueue cq;
    cq.front = cq.rear = -1;
    do {
        printf("\n--- MENU ---");
        printf("\n1. Insert\n2. Delete\n3. Traversal\n4. Exit\n");
        printf("Choice ? ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &item);
                cqinsert(&cq, item);
                break;
            case 2:
                if (isempty(cq.front))
                    printf("\nCircular Queue Underflow\n");
                else {
                    item = cqdelete(&cq);
                    printf("Item deleted: %d\n", item);}
                break;
            case 3:
                traversal(cq);
                break;}
    } while (choice != 4);
    return 0;}
