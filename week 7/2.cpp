#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
typedef struct {
    char s[MAX];
    int top;
} stack;

void push(stack *sp, char item) {
    sp->s[++(sp->top)] = item;}

char pop(stack *sp) {
    return sp->s[(sp->top)--];}

char peek(stack st) {
    return st.s[st.top];}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;}

void infixToPostfix(char I[], char P[]) {
    stack st;
    st.top = -1;
    int i = 0, j = 0;
    char item;

    push(&st, '(');
    strcat(I, ")");

    while (st.top != -1) {
        item = I[i];

        if (isalnum(item)) {
            P[j++] = item;} 
        else if (item == '(') {
            push(&st, item);} 
        else if (item == '+' || item == '-' || item == '*' || item == '/' || item == '^') {
            while (precedence(peek(st)) >= precedence(item)) {
                P[j++] = pop(&st); }
            push(&st, item);} 
        else if (item == ')') {
            while (peek(st) != '(') {
                P[j++] = pop(&st); }
            pop(&st); }
        i++;}
    P[j] = '\0';}

int main() {
    char I[MAX], P[MAX];
    printf("Enter Infix: ");
    scanf("%s", I);

    infixToPostfix(I, P);

    printf("Postfix: %s\n", P);
    return 0;}
