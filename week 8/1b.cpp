#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype {
    int INFO;
    struct nodetype *NEXT;
} node;

typedef struct queue {
    node *front, *rear;
} linkedqueue;

int isempty(linkedqueue q) {
    if (q.front == NULL)
        return 1;
    else
        return 0;
}

linkedqueue insert(linkedqueue q, int item) {
    node *pnew = (node *)malloc(sizeof(node));
    pnew->INFO = item;
    pnew->NEXT = NULL;

    if (q.rear == NULL) {
        q.front = q.rear = pnew;
    } else {
        (q.rear)->NEXT = pnew;
        q.rear = pnew;
    }
    printf("Item inserted...\n");
    return q;
}

linkedqueue deleteNode(linkedqueue q) {
    node *pdel;
    if (isempty(q)) {
        printf("\nQueue empty - Deletion not possible\n");
        return q;
    }

    pdel = q.front;
    if (q.front == q.rear) {
        q.front = q.rear = NULL;
    } else {
        q.front = (q.front)->NEXT;
    }
    free(pdel);
    printf("Node deleted...\n");
    return q;
}

void traversal(linkedqueue q) {
    if (isempty(q)) {
        printf("\nQueue empty\n");
    } else {
        node *p = q.front;
        printf("\nContents of Queue:\nFront-> ");
        while (p != NULL) {
            printf("%d ", p->INFO);
            p = p->NEXT;
        }
        printf("<-Rear\n");
    }
}

int main() {
    int choice, item;
    linkedqueue q;
    q.front = q.rear = NULL;

    do {
        printf("\nMENU (Queue operations):");
        printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Exit\n");
        printf("Choice ? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter int value to be inserted: ");
                scanf("%d", &item);
                q = insert(q, item);
                break;
            case 2:
                q = deleteNode(q);
                break;
            case 3:
                traversal(q);
                break;
        }
    } while (choice != 4);

    return 0;
}
