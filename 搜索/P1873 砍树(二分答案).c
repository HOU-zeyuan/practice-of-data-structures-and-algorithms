#include <stdio.h>
#include <stdlib.h>

long long int n, total_height;
long long int *heights;

int is_enough(long long int value, long long int key){
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        if(heights[i]>value) sum+=(heights[i]-value);
    }
    if(sum>=key) return 1;
    else return 0;
}

long long int binary_search(long long int left, long long int right, long long int key){
    long long int best;
    while(left<=right){
        long long int mid=left+(right-left)/2;
        if(is_enough(mid, key)) left=mid+1, best=mid;
        else right=mid-1;
    }
    return best;
}

int main() {
    scanf("%lld %lld", &n, &total_height);
    heights=(long long int *)malloc(n*sizeof(long long int));
    long long int max_height=0;
    for(long long int i=0;i<n;i++){
        scanf("%lld", &heights[i]);
        if(heights[i]>max_height) max_height=heights[i];
    }

    printf("%lld", binary_search(0, max_height, total_height));

    free(heights);
    return 0;
}