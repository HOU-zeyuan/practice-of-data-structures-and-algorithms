#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int n, m;
long long int *arr;

void counting_sort(long long int n, long long int value_range){
    long long int *count = (long long int*)malloc((value_range+1)*sizeof(long long int));
    memset(count, 0, sizeof(long long int)*(value_range+1));
    for(long long int i=0;i<n;i++) count[arr[i]]++;
    for(long long int i=1;i<=value_range;i++) count[i]+=count[i-1];

    long long int *result = (long long int*)malloc(n*sizeof(long long int));
    for(long long int i=n-1;i>=0;i--){
        result[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }

    for(long long int i=0;i<n;i++) arr[i]=result[i];
    free(result);
    free(count);
}

int main(){   
    scanf("%lld %lld", &n, &m);
    arr=(long long int*)malloc(n*sizeof(long long int));
    for(long long int i=0;i<n;i++) scanf("%lld",&arr[i]);

    counting_sort(n, m);
    
    for(long long int i=0;i<n;i++){
        if(i!=n-1)printf("%lld ", arr[i]);
        else printf("%lld\n", arr[i]);
    }

    free(arr);
    return 0;
}
