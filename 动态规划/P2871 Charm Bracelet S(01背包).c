#include <stdio.h>
#include <stdlib.h>

int n, m;
int *cost, *value, *dp;

int main() {
    scanf("%d %d", &n, &m);
    cost=(int*)malloc(sizeof(int)*(n+1));
    value=(int*)malloc(sizeof(int)*(n+1));
    dp=(int*)malloc(sizeof(int)*(m+1));
    for(int i=0;i<=n;i++) dp[i]=0;
    for(int i=1;i<=n;i++) scanf("%d %d", &cost[i], &value[i]);

    for(int i=1;i<=n;i++){
        for(int j=m;j>=cost[i];j--){
            dp[j]=dp[j]>dp[j-cost[i]]+value[i]?dp[j]:dp[j-cost[i]]+value[i];
        }
    }

    printf("%d", dp[m]);
    free(dp), free(cost), free(value);
    return 0;
}