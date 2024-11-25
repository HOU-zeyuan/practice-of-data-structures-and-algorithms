#include <stdio.h>
#include <stdlib.h>

long long int num, sum;
long long int *length;

int is_valid(long long int n){
    long long int ans = 0;
    for(long long int i = 0; i < num; i++){
        ans += length[i] / n;
        if(ans >= sum) return 1; // 提前返回，节省计算
    }
    return 0;
}

long long int binary_search(long long int l, long long int r){
    long long int best = 0;
    while(l <= r){
        long long int mid = l + (r - l) / 2;
        if(is_valid(mid)){
            best = mid;  // 更新最优解
            l = mid + 1; // 尝试更大的长度
        }
        else r = mid - 1; // 尝试更小的长度
    }
    return best;
}

int main(){
    scanf("%lld %lld", &num, &sum);
    length = (long long int *)malloc(num * sizeof(long long int));
    long long int left = 1, right = 0;

    for(long long int i = 0; i < num; i++){
        scanf("%lld", &length[i]);
        if(length[i] > right) right = length[i]; // 找到最大值
    }

    printf("%lld", binary_search(left, right));

    free(length);
    return 0;
}
