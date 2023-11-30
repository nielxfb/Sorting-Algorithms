#include <stdio.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minIdx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d", arr[i
        if(i != n-1) printf(" ");
    }
    puts("");
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    puts("Before:");
    printArr(arr, n);

    selectionSort(arr, n);
    puts("After:");
    printArr(arr, n);

    return 0;
}