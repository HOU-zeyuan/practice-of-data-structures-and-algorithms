#include <stdio.h>
#include <stdlib.h>

int n, m, *arr;
int **data, **temp, **dp;

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

    dp=(int**)malloc(sizeof(int*)*(n+2));
    for(int i=0;i<=n+1;i++){
        dp[i]=(int*)malloc(sizeof(int)*(m+1));
        for(int j=0;j<=m;j++) dp[i][j]=0x3f3f3f3f;
    }
    temp=(int**)malloc(sizeof(int*)*(n+2));
    for(int i=0;i<=n+1;i++){
        temp[i]=(int*)malloc(sizeof(int)*(m+1));
        for(int j=0;j<=m;j++) temp[i][j]=0;
    }

    data=(int**)malloc(sizeof(int*)*(n+2));
    for(int i=0;i<=n+1;i++) data[i]=(int*)malloc(sizeof(int)*(n+1));
    init_data();

    dp[0][0]=0;//前i个村庄有j个邮局
    for(int j=1;j<=m;j++){//dp递推需要先枚举j
        temp[n+1][j]=n;//当i=n时，为temp[i+1][j]赋值
        for(int i=n;i>=1;i--){
            int min=0x3f3f3f3f, index=0;
            for(int k=temp[i][j-1];k<=temp[i+1][j];k++){
                if(dp[k][j-1]+data[k+1][i]<min){
                    min=dp[k][j-1]+data[k+1][i];
                    index=k;
                }
            }
            dp[i][j]=min, temp[i][j]=index;
        }
    }

    printf("%d", dp[n][m]);
    for(int i=0;i<=n+1;i++) free(temp[i]), free(dp[i]), free(data[i]);
    free(dp), free(arr), free(temp), free(data);
    return 0;
}
//data[i][j]=data[i][j-1]+arr[j]-arr[i+(j-i)/2]
//data[i+1][j]=data[i+1][j-1]+arr[j]-arr[i+1+(j-i-1)/2]
//两式相减:data[i+1][j]+data[i][j-1]-data[i+1][j-1]-data[i][j]=arr[i+1+(j-i-1)/2]-arr[i+(j-i)/2]>=0
//data[i][j]和dp[i][j]满足四边形不等式，故求最优的dp[i][j]时，i的取值范围为[temp[i][j-1],temp[i+1][j]]
//最优转移点k单调不减