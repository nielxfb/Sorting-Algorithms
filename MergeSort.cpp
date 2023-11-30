#include <stdio.h>

void merge(int arr[], int low, int mid, int high){
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int leftArr[leftSize], rightArr[rightSize];

    for(int i = 0; i < leftSize; i++)
        leftArr[i] = arr[low + i];

    for(int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];

    int leftPtr, rightPtr, arrPtr = low;
    leftPtr = rightPtr = 0;

    while(leftPtr < leftSize && rightPtr < rightSize)
        arr[arrPtr++] = (leftArr[leftPtr] < rightArr[rightPtr]) ? leftArr[leftPtr++] : rightArr[rightPtr++];

    while(leftPtr < leftSize)
        arr[arrPtr++] = leftArr[leftPtr++];

    while(rightPtr < rightSize)
        arr[arrPtr++] = rightArr[rightPtr++];

}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n-1);
    puts("After:");
    printArr(arr, n);

    return 0;
}