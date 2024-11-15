#include <stdio.h>
#include <stdlib.h>

long long int n;
long long int *arr;

void swap(long long int *a, long long int *b){
    long long int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(long long int *heap, long long int n, long long int index){
    long long int left=index*2+1, right=index*2+2, largest=index;
    if(left<n && heap[left]>heap[largest]) largest=left;
    if(right<n && heap[right]>heap[largest]) largest=right;

    if(largest!=index){
        swap(&heap[index], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void heap_sort(long long int *arr, long long int n){
    for(long long int i=n/2-1;i>=0;i--) heapify(arr, n, i);
    for(long long int i=n-1;i>=0;i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){   
    scanf("%lld", &n);
    arr=(long long int*)malloc(n*sizeof(long long int));
    for(long long int i=0;i<n;i++) scanf("%lld",&arr[i]);

    heap_sort(arr, n);
    
    for(long long int i=0;i<n;i++){
        if(i!=n-1)printf("%lld ", arr[i]);
        else printf("%lld\n", arr[i]);
    }

    free(arr);
    return 0;
}
