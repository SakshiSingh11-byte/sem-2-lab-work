#include<stdio.h>
#include<stdlib.h>

struct nodetype {
    int INFO;
    struct nodetype *NEXT;
};
typedef struct nodetype node;

int isempty(node *top) {
    if (top == NULL) return 1;
    else return 0;
}

node* push(node *top, int item) {
    node *pnew = (node *)malloc(sizeof(node));
    pnew->INFO = item;
    pnew->NEXT = top;
    printf("Node inserted...\n");
    return pnew;
}

node* pop(node *top) {
    node *pdel;
    if (isempty(top)) {
        printf("\nStack empty - Deletion not possible\n");
        return top;
    }
    pdel = top;
    top = top->NEXT;
    free(pdel);
    printf("Node deleted...\n");
    return top;
}

void traversal(node *top) {
    if (isempty(top)) {
        printf("\nStack empty\n");
    } else {
        node *p = top;
        printf("\nContents of Stack:\nTop-> ");
        while (p != NULL) {
            printf("%d ", p->INFO);
            p = p->NEXT;
        }
        printf("\n");
    }
}

int main() {
    node *top = NULL;
    int choice, item;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &item);
                top = push(top, item);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                traversal(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
