#include <stdio.h>
#include <stdlib.h>

int n, t, money;
int time, cost;
int **dp;

int main() {
    scanf("%d %d %d", &n, &t, &money);
    dp=(int**)malloc((t+1)*sizeof(int*));
    for(int i=0;i<=t;i++){
        dp[i] =(int*)malloc((money+1)*sizeof(int));
        for(int j=0;j<=money;j++) dp[i][j]=0;
    }
    
    for(int i=1;i<=n;i++){
        scanf("%d %d", &time, &cost);
        for(int j=t;j>=time;j--){
            for(int k=money;k>=cost;k--){
                dp[j][k]=dp[j][k]>dp[j-time][k-cost]+1?dp[j][k]:dp[j-time][k-cost]+1;
            }
        }
    }

    printf("%d", dp[t][money]);
    for(int i=0;i<=t;i++) free(dp[i]);
    free(dp);
    return 0;
}