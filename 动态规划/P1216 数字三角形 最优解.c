#include <stdio.h>
#include <string.h>
#include <math.h>

int n, input, ans=0;
int dp[1001];

int main(){
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            scanf("%d", &input);
            dp[j]=fmax(dp[j], dp[j-1])+input;
        }
    }

    for(int i=1;i<=n;i++) ans=fmax(ans, dp[i]);
    printf("%d", ans);
    return 0;
}