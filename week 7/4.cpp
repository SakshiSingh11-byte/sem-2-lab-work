#include <stdio.h>
#include <ctype.h>
#include <string.h>
char s[100];
int top = -1;

void push(char item) {
    s[++top] = item;}

char pop() {
    return s[top--];}

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;}

void convert(char I[], char P[]) {
    int i = 0, j = 0;
    push('(');
    strcat(I, ")");

    while (top != -1) {
        if (isalnum(I[i])) {
            P[j++] = I[i];
        } else if (I[i] == '(') {
            push(I[i]);
        } else if (I[i] == ')') {
            while (s[top] != '(') {
                P[j++] = pop();}
            pop();
        } else {
            while (prec(s[top]) >= prec(I[i])) {
                P[j++] = pop();}
            push(I[i]);}
        i++;}
    P[j] = '\0';}

int main() {
    char infix[100] = "(A+B)*(C+B)*(E/F)";
    char postfix[100];
    printf("Infix: %s\n", infix);
    convert(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;}
