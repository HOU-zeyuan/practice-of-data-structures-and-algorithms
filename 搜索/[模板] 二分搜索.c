#include <stdio.h>
#include <stdlib.h>

long long int n, key;
long long int *arr;

long long int binary_search(long long int left, long long int right, long long int key){
    while(left<=right){
        long long int mid=left+(right-left)/2;
        if(arr[mid]<key) left=mid+1;
        else right=mid-1;
    }
    return left;
}

int main(){
    scanf("%lld %lld", &n, &key);
    arr=(long long int*)malloc(sizeof(long long int)*n);
    for(long long int i=0; i<n; i++) scanf("%lld", &arr[i]);
    
    printf("%lld", binary_search(0, n-1, key));

    free(arr);
    return 0;
}
