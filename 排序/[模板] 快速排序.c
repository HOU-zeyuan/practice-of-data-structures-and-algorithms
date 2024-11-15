#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int n;
long long int *arr;

void quick_sort(long long int l, long long int r){
    if(l>=r) return;
    
    long long int left=l, right=r, pivot=arr[l+rand()%(r-l+1)];
    while(left<=right){
        while(arr[left]<pivot) left++;
        while(arr[right]>pivot) right--;

        if(left<=right){
            long long int temp=arr[left];
            arr[left++]=arr[right];
            arr[right--]=temp;
        }
    }
    quick_sort(l,right);
    quick_sort(left,r);
}

int main(){   
    srand((int)time(NULL));
    scanf("%lld",&n);
    arr=(long long int*)malloc(n*sizeof(long long int));
    for(long long int i=0; i<n; i++) scanf("%lld", &arr[i]);

    quick_sort(0,n-1);
    
    for(long long int i=0; i<n; i++){
        if(i!=n-1) printf("%lld ", arr[i]);
        else printf("%lld\n", arr[i]);
    }

    free(arr);
    return 0;
}
