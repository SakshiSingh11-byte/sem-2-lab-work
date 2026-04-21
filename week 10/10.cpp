#include <stdio.h>
#include <string.h>

void insertionSortInt(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSortChar(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSortInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void swapChar(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int partitionChar(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swapChar(&arr[i], &arr[j]);
        }
    }
    swapChar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortChar(char arr[], int low, int high) {
    if (low < high) {
        int pi = partitionChar(arr, low, high);
        quickSortChar(arr, low, pi - 1);
        quickSortChar(arr, pi + 1, high);
    }
}

int main() {
    int choice, n, i;
    int intArr[100];
    char charArr[100];

    printf("Choose an option:\n");
    printf("1. Insertion Sort (Integers)\n");
    printf("2. Bubble Sort (Characters)\n");
    printf("3. Selection Sort (Integers)\n");
    printf("4. Quick Sort (Characters)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter number of integers: ");
            scanf("%d", &n);
            printf("Enter %d integers: ", n);
            for(i = 0; i < n; i++) scanf("%d", &intArr[i]);
            insertionSortInt(intArr, n);
            printf("Sorted: ");
            for(i = 0; i < n; i++) printf("%d ", intArr[i]);
            break;

        case 2:
            printf("Enter string (characters): ");
            scanf("%s", charArr);
            bubbleSortChar(charArr, strlen(charArr));
            printf("Sorted: %s", charArr);
            break;

        case 3:
            printf("Enter number of integers: ");
            scanf("%d", &n);
            printf("Enter %d integers: ", n);
            for(i = 0; i < n; i++) scanf("%d", &intArr[i]);
            selectionSortInt(intArr, n);
            printf("Sorted: ");
            for(i = 0; i < n; i++) printf("%d ", intArr[i]);
            break;

        case 4:
            printf("Enter string (characters): ");
            scanf("%s", charArr);
            quickSortChar(charArr, 0, strlen(charArr) - 1);
            printf("Sorted: %s", charArr);
            break;

        default:
            printf("Invalid choice!");
    }
    printf("\n");
    return 0;
}
