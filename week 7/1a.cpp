#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct {
    int s[N];
    int top;
} stack;

void push(stack *sp, int item) {
    if (sp->top == N - 1) {
        printf("Stack full/overflow - Insertion not possible\n");
        return;}
    (sp->top)++;
    sp->s[sp->top] = item;}

int pop(stack *sp) {
    int item;
    if (sp->top == -1) {
        printf("Stack empty/underflow - Deletion not possible\n");
        return 0;}
    item = sp->s[sp->top];
    (sp->top)--;
    return item;}

int peek(stack st) {
    if (st.top == -1) {
        printf("Stack empty\n");
        return 0; }
    return st.s[st.top];}

void traversal(stack st) {
    int i = 0;
    if (st.top == -1) {
        printf("\nStack empty\n");
        return;}
    printf("\nContents of Stack:\n");
    while (i <= st.top) {
        printf("%d ", st.s[i++]);}
    printf("<-top\n");}

int main() {
    int choice, item;
    stack st;
    st.top = -1;

    while (1) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter item: ");
            scanf("%d", &item);
            push(&st, item);
        } else if (choice == 2) {
            item = pop(&st);
            if (item != 0) printf("Popped: %d\n", item);
        } else if (choice == 3) {
            printf("Top: %d\n", peek(st));
        } else if (choice == 4) {
            traversal(st);
        } else {
            exit(0);}}
    return 0;}
