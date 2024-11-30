#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int n, m, value, cost, count, ans=0, head, tail;
long long int *dp, *arr1, *arr2;

int main(){
    scanf("%lld %lld", &n, &m);
    dp=(long long int*)malloc(sizeof(long long int)*(m+1));
    arr1=(long long int*)malloc(sizeof(long long int)*(m+1));
    arr2=(long long int*)malloc(sizeof(long long int)*(m+1));
    for(long long int i=0;i<=m;i++) dp[i]=arr1[i]=arr2[i]=0;

    for(long long int i=1;i<=n;i++){
        scanf("%lld %lld %lld", &value, &cost, &count);
        if(!cost){
            ans+=value*count;
            continue;
        }
        count=fmin(count, m/cost);//限制count不超出背包容量

        for(int j=0;j<cost;j++){//遍历余数
            head=tail=0;
            int x=(m-j)/cost;//计算余数j下，最多能装多少个物品
            for(int k=0;k<=x;k++){
                while(head<tail && arr1[head]<k-count) head++;//移除队列中超出范围的物品
                while(head<tail && dp[j+k*cost]-k*value>=arr2[tail-1]) tail--;//维护队列单调性
                arr1[tail] = k, arr2[tail++] = dp[j + k * cost] - k * value;  // arr1记录物品选择次数，arr2记录对应的动态规划值
                //dp[j+k*cost]-k*value指背包容量为j+k*cost时，除去k个当前物品的贡献后，剩余物品所能提供的最大价值
                dp[j+k*cost]=fmax(dp[j+k*cost], arr2[head]+k*value);
            }
        }
    }
    printf("%lld", ans+dp[m]);
    free(dp), free(arr1), free(arr2);
    return 0;
}