#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;};

typedef struct {
    struct node *top;
} stack;

void push(stack *sp, int item) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Stack overflow\n");
        return;}
    t->data = item;
    t->next = sp->top;
    sp->top = t;}

int pop(stack *sp) {
    struct node *t;
    int item;
    if (sp->top == NULL) {
        printf("Stack empty\n");
        return 0;}
    t = sp->top;
    item = t->data;
    sp->top = t->next;
    free(t);
    return item;}

void traversal(stack st) {
    struct node *p = st.top;
    if (p == NULL) {
        printf("Stack empty\n");
        return;}
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next; }
    printf("\n");}

int main() {
    int choice, item;
    stack st;
    st.top = NULL;

    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter item: ");
            scanf("%d", &item);
            push(&st, item);
        } else if (choice == 2) {
            item = pop(&st);
            if (item != 0) printf("Popped: %d\n", item);
        } else if (choice == 3) {
            traversal(st);
        } else {
            exit(0);} }
    return 0;}
