#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;};

struct Node* last = NULL;

void createList(void);
void displayList(void);
void deleteByIndex(void);
void clearInput(void);

int main() {
    int choice;
    while (1) {
        printf("\n--- CIRCULAR LIST (INDEX BASED) ---");
        printf("\n1. Create/Add Multiple Nodes");
        printf("\n2. Delete by Index");
        printf("\n3. Display List");
        printf("\n4. Exit");
        printf("\nChoice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Use numbers.\n");
            clearInput();
            continue;}
        
        if (choice == 1) createList();
        else if (choice == 2) deleteByIndex();
        else if (choice == 3) displayList();
        else if (choice == 4) break;
        else printf("Invalid option.\n");}
    return 0;}

void createList() {
    int n, i, val;
    struct Node* newNode;

    printf("How many nodes to add? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Enter a positive integer.\n");
        clearInput();
        return;}

    for (i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        
        if (last == NULL) {
            newNode->next = newNode; 
            last = newNode;
        } else {
            newNode->next = last->next; 
            last->next = newNode;       
            last = newNode;             }}
    printf("Successfully added %d nodes.\n", n);}

void deleteByIndex() {
    struct Node *curr, *prev;
    int index, count = 1;
    if (last == NULL) {
        printf("Empty list.\n");
        return;}
    printf("Enter index to delete (starting from 1): ");
    if (scanf("%d", &index) != 1 || index <= 0) {
        printf("Invalid index.\n");
        clearInput();
        return;}
    curr = last->next;
    prev = last;
    do {
        if (count == index) {
            if (curr == last && curr->next == last) {
                last = NULL;} 
            else {
                if (curr == last) {
                    last = prev;}
                prev->next = curr->next;}
            int deletedVal = curr->data;
            free(curr);
            printf("Deleted value %d at index %d\n", deletedVal, index);
            return;}
        prev = curr;
        curr = curr->next;
        count++;
    } while (curr != last->next);
    printf("Index %d out of bounds.\n", index);}

void displayList() {
    struct Node* temp;
    if (last == NULL) {
        printf("List is empty.\n");
        return;}
    temp = last->next;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(head)\n");}

void clearInput() {
    while (getchar() != '\n');}
