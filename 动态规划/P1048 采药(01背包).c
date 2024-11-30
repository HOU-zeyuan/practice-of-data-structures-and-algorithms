#include <stdio.h>
#include <stdlib.h>

int T, M;
int **arr, **dp;

int main() {
    scanf("%d %d", &T, &M);
    arr=(int**)malloc(sizeof(int*)*(M+1));
    for(int i=0;i<=M;i++) arr[i]=(int*)malloc(sizeof(int)*2);
    dp=(int**)malloc(sizeof(int*)*(M+1));
    for(int i=0;i<=M;i++) dp[i]=(int*)malloc(sizeof(int)*(T+1));
    for(int i=0;i<=M;i++) for(int j=0;j<=T;j++) dp[i][j]=0;
    for(int i=1;i<=M;i++) scanf("%d %d", &arr[i][0], &arr[i][1]);

    for(int i=1;i<=M;i++){
        for(int j=0;j<=T;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i][0]){
                dp[i][j]=dp[i][j]>dp[i-1][j-arr[i][0]]+arr[i][1]?dp[i][j]:dp[i-1][j-arr[i][0]]+arr[i][1];
            }
        }
    }

    printf("%d\n", dp[M][T]);
    for(int i=0;i<=M;i++) free(arr[i]), free(dp[i]);
    free(arr), free(dp);
    return 0;
}