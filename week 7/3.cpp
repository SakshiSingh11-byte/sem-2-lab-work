#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
typedef struct {
    int s[MAX];
    int top;
} stack;

void push(stack *sp, int item) {
    sp->s[++(sp->top)] = item;}

int pop(stack *sp) {
    return sp->s[(sp->top)--];}

int evaluatePostfix(char P[]) {
    stack st;
    st.top = -1;
    int i = 0, v1, v2;

    while (P[i] != '\0') {
        if (isdigit(P[i])) {
            push(&st, P[i] - '0');
        } else {
            v2 = pop(&st);
            v1 = pop(&st);
            switch (P[i]) {
                case '+': push(&st, v1 + v2); break;
                case '-': push(&st, v1 - v2); break;
                case '*': push(&st, v1 * v2); break;
                case '/': push(&st, v1 / v2); break;
                case '^': push(&st, pow(v1, v2)); break;}}
        i++;}
    return pop(&st);}

int main() {
    char P[MAX];
    printf("Enter Postfix: ");
    scanf("%s", P);
    printf("Result: %d\n", evaluatePostfix(P));
    return 0;}
