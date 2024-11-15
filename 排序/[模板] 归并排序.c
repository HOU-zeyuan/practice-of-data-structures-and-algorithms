#include <stdio.h>
#include <stdlib.h>

long long int n;
long long int *arr;

void merge_sort(long long int *arr, long long int left, long long int right){
    if(right<=left) return;

    long long int mid=(left+right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);

    long long int i=left, j=mid+1, k=0;
    long long int *temp=(long long int *)malloc((right-left+1)*sizeof(long long int));
    while(i<=mid && j<=right){
        if(arr[i]>arr[j]) temp[k++]=arr[j++];
        else temp[k++]=arr[i++];   
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=right) temp[k++]=arr[j++];

    for(long long int i=0;i<right-left+1;i++) arr[left+i]=temp[i];
    free(temp);
}

int main(){   
    scanf("%lld", &n);
    arr=(long long int*)malloc(n*sizeof(long long int));
    for(long long int i=0;i<n;i++) scanf("%lld",&arr[i]);

    merge_sort(arr, 0, n-1);
    
    for(long long int i=0;i<n;i++){
        if(i!=n-1)printf("%lld ", arr[i]);
        else printf("%lld\n", arr[i]);
    }

    free(arr);
    return 0;
}
