#include <stdio.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int lastIdx = 0;
int heap[1000];

void upHeapify(int currIdx){
    if(currIdx == 1) return;
    int parentIdx = currIdx / 2;
    if(heap[currIdx] > heap[parentIdx]){
        swap(&heap[currIdx], &heap[parentIdx]);
        upHeapify(parentIdx);
    }
}

void insertion(int val){
    heap[++lastIdx] = val;
    upHeapify(lastIdx);
}

void downHeapify(int currIdx){
    int leftIdx = currIdx * 2;
    int rightIdx = currIdx * 2 + 1;
    int largestIdx = currIdx;

    if(leftIdx <= lastIdx && heap[leftIdx] > heap[largestIdx])
        largestIdx = leftIdx;
    if(rightIdx <= lastIdx && heap[rightIdx] > heap[largestIdx])
        largestIdx = rightIdx;

    if(largestIdx != currIdx){
        swap(&heap[currIdx], &heap[largestIdx]);
        downHeapify(largestIdx);
    }
}

void extract(){
    swap(&heap[1], &heap[lastIdx]);
    lastIdx--;
    downHeapify(1);
}

void heapSort(int arr[], int n){
	for(int i = 0; i < n; i++){
		insertion(arr[i]);
	}
	
	for(int i = 0; i < n; i++){
		extract();
	}
	
	for(int i = 0; i < n; i++){
		arr[i] = heap[i+1];
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

    heapSort(arr, n);
    puts("After:");
    printArr(arr, n);

    return 0;
}
