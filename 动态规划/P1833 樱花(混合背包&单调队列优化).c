#include <stdio.h>
#include <stdlib.h>

int h1, h2, m1, m2, n, time;
int cost, value, count, head, tail, *arr1, *arr2, *dp;

int main() {
    scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
    time=(h2-h1)*60+(m2-m1);
    arr1=(int*)malloc((time+1)*sizeof(int));
    arr2=(int*)malloc((time+1)*sizeof(int));
    dp=(int*)malloc((time+1)*sizeof(int));
    for(int i=0;i<=time;i++) dp[i]=0;

    for(int i=1;i<=n;i++){
        scanf("%d %d %d", &cost, &value, &count);

        if(!count){
            for(int j=cost;j<=time;j++){
                dp[j]=dp[j]>dp[j-cost]+value?dp[j]:dp[j-cost]+value;
            }
        }
        else{
            for(int j=0;j<cost;j++){
                head=tail=0;
                int x=(time-j)/cost;
                for(int k=0;k<=x;k++){
                    while(head<tail && arr1[head]<k-count) head++;
                    while(head<tail && dp[j+k*cost]-value*k>=arr2[tail-1]) tail--;
                    arr1[tail]=k, arr2[tail++]=dp[j+k*cost]-value*k;
                    dp[j+k*cost]=dp[j+k*cost]>arr2[head]+value*k?dp[j+k*cost]:arr2[head]+value*k;
                }
            }
        }
    }
    printf("%d", dp[time]);
    free(dp), free(arr1), free(arr2);
    return 0;
}
