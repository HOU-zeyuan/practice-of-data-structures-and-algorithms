#include <stdio.h>
#include <stdlib.h>

long long int n, m;
long long int *cost, *value, *dp;

int main() {
    scanf("%lld %lld", &m, &n);
    cost=(long long int*)malloc(sizeof(long long int)*(n+1));
    value=(long long int*)malloc(sizeof(long long int)*(n+1));
    dp=(long long int*)malloc(sizeof(long long int)*(m+1));
    for(long long int i=0;i<=m;i++) dp[i]=0;
    for(long long int i=1;i<=n;i++) scanf("%lld %lld", &cost[i], &value[i]);

    for(long long int i=1;i<=n;i++){
        for(long long int j=cost[i];j<=m;j++){
            dp[j]=dp[j]>dp[j-cost[i]]+value[i]?dp[j]:dp[j-cost[i]]+value[i];
        }
    }

    printf("%lld", dp[m]);
    free(dp), free(cost), free(value);
    return 0;
}