#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[10000];
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000;
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting arr using inbuilt quicksort method
    qsort(arr, n, sizeof(int), compare);

    return 0;
}