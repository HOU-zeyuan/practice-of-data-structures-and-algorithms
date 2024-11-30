#include <stdio.h>
#include <string.h>
#include <math.h>

int n;
double position[16][2], distance[16][16], arr[16][32769];
double ans;

void calculate_distance(){
    for(int i=0;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            distance[i][j]=sqrt(pow(position[i][0]-position[j][0], 2) + pow(position[i][1]-position[j][1], 2));
            distance[j][i]=distance[i][j];
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%lf %lf", &position[i][0], &position[i][1]);
    position[0][0]=position[0][1]=0;//初始位置(0, 0)
    calculate_distance();
    memset(arr, 127, sizeof(arr));//初始化为无穷大，127是double类型无穷大的近似值
    ans=arr[0][0];

    for(int i=1;i<=n;i++) arr[i][1<<(i-1)]=distance[0][i];//从(0, 0)到每个点的距离

    for(int i=0;i<(1<<n);i++){//i的二进制表示法，表示从(0, 0)出发经过哪些点
        for(int j=1;j<=n;j++){
            if((i&(1<<(j-1)))==0) continue;//如果第j个点没有经过，跳过
            for(int k=1;k<=n;k++){//k是j之前的点，搜索更近的路径
                if(j==k) continue;
                if((i&(1<<(k-1)))==0) continue;//如果第k个点没有经过，跳过
                arr[j][i]=fmin(arr[j][i], arr[k][i-(1<<(j-1))]+distance[j][k]);//更新，[i-(1<<(j-1))]表示原路径从(0, 0)出发到达k点的部分
            }
        }
    }

    for(int i=1;i<=n;i++) ans=fmin(ans, arr[i][(1<<n)-1]);//终点为i，经过所有点
    printf("%.2lf\n", ans);
    return 0;
}