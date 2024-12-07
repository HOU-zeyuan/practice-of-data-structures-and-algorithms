#include <stdio.h>
#include <stdlib.h>

int n, m, *arr;
int **data, **dp;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b, *b=temp;
}

void three_qsort(int left, int right){
    if(left>=right) return;
    int l=left, r=right, pivot=arr[l+(r-l)/2];
    int i=l;
    while(i<=r){
        if(arr[i]<pivot) swap(&arr[i++], &arr[l++]);
        else if(arr[i]>pivot) swap(&arr[i], &arr[r--]);
        else i++;
    }
    three_qsort(left, l-1);
    three_qsort(r+1, right);
}

void init_data(){//从i到j设置一个邮局的距离和
    for(int i=1;i<=n;i++){
        data[i][i]=0;
        for(int j=i+1;j<=n;j++){
            data[i][j]=data[i][j-1]+arr[j]-arr[i+(j-i)/2];
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    arr=(int*)malloc(sizeof(int)*(n+1));
    for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
    three_qsort(1, n);

    dp=(int**)malloc(sizeof(int*)*(n+1));
    for(int i=0;i<=n;i++){
        dp[i]=(int*)malloc(sizeof(int)*(m+1));
        for(int j=0;j<=m;j++) dp[i][j]=0x3f3f3f3f;
    }

    data=(int**)malloc(sizeof(int*)*(n+1));
    for(int i=0;i<=n;i++) data[i]=(int*)malloc(sizeof(int)*(n+1));
    init_data();

    dp[0][0]=0;//前i个村庄有j个邮局
    for(int j=1;j<=m;j++){//dp递推需要先枚举j
        for(int i=1;i<=n;i++){
            for(int k=0;k<i;k++){
                dp[i][j]=dp[i][j]>dp[k][j-1]+data[k+1][i]?dp[k][j-1]+data[k+1][i]:dp[i][j];
            }
        }
    }

    printf("%d", dp[n][m]);
    for(int i=0;i<=n;i++) free(dp[i]);
    free(dp), free(arr);
    return 0;
}