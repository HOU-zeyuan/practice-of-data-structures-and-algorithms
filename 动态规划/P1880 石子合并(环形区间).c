#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int n, *input, *sum, **dp1, **dp2, ans1=INT_MAX, ans2=INT_MIN;

int main(){
    scanf("%d", &n);
    input = (int *)malloc(sizeof(int) * (2 * n + 1));
    sum = (int *)malloc(sizeof(int) * (2 * n + 1));
    dp1 = (int **)malloc(sizeof(int *) * (2 * n + 1));
    dp2 = (int **)malloc(sizeof(int *) * (2 * n + 1));
    for (int i = 0; i <= 2 * n; i++){
        dp1[i] = (int *)malloc(sizeof(int) * (2 * n + 1));
        dp2[i] = (int *)malloc(sizeof(int) * (2 * n + 1));
        for (int j = 0; j <= 2 * n; j++){
            dp1[i][j] = INT_MAX;
            dp2[i][j] = INT_MIN;
        }
    }
    for (int i = 1; i <= n; i++){
        scanf("%d", &input[i]);
        input[i + n] = input[i];//化环为链
    }
    sum[0] = 0;
    for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + input[i];//前缀和

    for (int i = 1; i <= 2 * n; i++) dp1[i][i] = dp2[i][i] = 0;
    for (int i = 2; i <= n; i++){//枚举区间长度
        for (int j = 1; j + i - 1 <= 2 * n; j++){//枚举区间起点
            int k = j + i - 1;//区间终点
            for (int l = j; l < k; l++){//枚举分割点
                dp1[j][k] = fmin(dp1[j][k], dp1[j][l] + dp1[l + 1][k]);
                dp2[j][k] = fmax(dp2[j][k], dp2[j][l] + dp2[l + 1][k]);
            }
            dp1[j][k] += sum[k] - sum[j - 1];
            dp2[j][k] += sum[k] - sum[j - 1];
        }
    }

    for (int i = 1; i <= n; i++){
        ans1 = fmin(ans1, dp1[i][i + n - 1]);
        ans2 = fmax(ans2, dp2[i][i + n - 1]);
    }
    printf("%d\n%d\n", ans1, ans2);
    for (int i = 0; i <= 2 * n; i++){
        free(dp1[i]);
        free(dp2[i]);
    }
    free(dp1), free(dp2), free(sum), free(input);
    return 0;
}