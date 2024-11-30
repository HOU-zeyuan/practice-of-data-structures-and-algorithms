#include <stdio.h>
#include <string.h>
#include <math.h>

int n, ans=0;
int arr[1001][1001], dp[1001][1001];

int main(){
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp)), memset(arr, 0, sizeof(arr));
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) scanf("%d", &arr[i][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=fmax(dp[i-1][j], dp[i-1][j-1])+arr[i][j];
        }
    }

    for(int i=1;i<=n;i++) ans=fmax(ans, dp[n][i]);
    printf("%d", ans);
    return 0;
}