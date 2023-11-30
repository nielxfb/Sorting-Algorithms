#include <stdio.h>

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
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

    insertionSort(arr, n);
    puts("After:");
    printArr(arr, n);

    return 0;
}