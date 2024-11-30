#include <stdio.h>
#include <stdlib.h>

long long int n, m, cnt=1;
long long int cost, value, count, *C, *V, *dp;

int main() {
    scanf("%lld %lld", &n, &m);
    C=(long long int*)malloc(sizeof(long long int)*(100*n+1));
    V=(long long int*)malloc(sizeof(long long int)*(100*n+1));
    dp=(long long int*)malloc(sizeof(long long int)*(m+1));
    for(long long int i=0;i<=m;i++) dp[i]=0;

    for(long long int i=1;i<=n;i++){
        scanf("%lld %lld %lld", &value, &cost, &count);
        for(long long int j=1;j<=count;j<<=1){
            C[cnt]=j*cost, V[cnt++]=j*value;//按二进制合并相同价值的物品
            count-=j;//合并后剩余的物品数量
        }
        if(count) C[cnt]=count*cost, V[cnt++]=count*value;//合并剩余的物品
            
    }

    for(long long int i=1;i<=cnt;i++){//cnt为合并后的物品数量
        for(long long int j=m;j>=C[i];j--){
            dp[j]=dp[j]>dp[j-C[i]]+V[i]?dp[j]:dp[j-C[i]]+V[i];
        }
    }

    printf("%lld", dp[m]);
    free(C), free(V), free(dp);
    return 0;
}