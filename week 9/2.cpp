#include <stdio.h>
#include <stdlib.h>
#define N 10

int linear_search(int a[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (a[i] == item) return i;}
    return -1;}

int linear_search_recursive(int a[], int n, int item, int index) {
    if (index >= n) return -1;
    if (a[index] == item) return index;
    return linear_search_recursive(a, n, item, index + 1);}

int binary_search(int a[], int n, int item) {
    int lb = 0, ub = n - 1, mid;
    while (lb <= ub) {
        mid = (lb + ub) / 2;
        if (item == a[mid]) return mid;
        else if (item < a[mid]) ub = mid - 1;
        else lb = mid + 1;}
    return -1;}

int binary_search_recursive(int a[], int lb, int ub, int item) {
    if (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (a[mid] == item) return mid;
        if (item < a[mid]) return binary_search_recursive(a, lb, mid - 1, item);
        return binary_search_recursive(a, mid + 1, ub, item);}
    return -1;}

int main() {
    int a[N], i, x, loc, choice, type;
    printf("Enter %d integer values:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);}

    printf("\n--- Search Menu ---\n1. Linear Search\n2. Binary Search\nChoice: ");
    scanf("%d", &type);
    printf("Enter value to search: ");
    scanf("%d", &x);
    printf("Choose Method:\n1. Non-Recursive\n2. Recursive\nChoice: ");
    scanf("%d", &choice);

    if (type == 1) {
        if (choice == 1) loc = linear_search(a, N, x);
        else loc = linear_search_recursive(a, N, x, 0);} 
    else if (type == 2) {
        if (choice == 1) loc = binary_search(a, N, x);
        else loc = binary_search_recursive(a, 0, N - 1, x);} 
    else {
        return 0;}

    if (loc == -1)
        printf("\nValue not found.\n");
    else
        printf("\nValue found at index: %d\n", loc);
    return 0;}
