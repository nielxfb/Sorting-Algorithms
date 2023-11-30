#include <stdio.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i != n-1) printf(" ");
    }
    puts("");
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    puts("Before:");
    printArr(arr, n);

    quickSort(arr, 0, n-1);
    puts("After");
    printArr(arr, n);

    return 0;
}