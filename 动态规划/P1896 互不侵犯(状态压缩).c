#include <stdio.h>
#include <stdlib.h>

int n, m, inx=0;
long long int dp[10][2000][100]={0}, situation[2000]={0}, count[2000]={0};//situation[i]表示第i行状态，count[i]表示第i行状态下的国王数量

void dfs(int x, int num, int node){//搜索一行所有的状态和对应的位于该行国王的数量
    if(node>=n){
        situation[++inx]=x;//inx对于一行的不同状态数量
        count[inx]=num;
        return;
    }
    dfs(x, num, node+1);//不在node放置国王
    dfs(x+(1<<node), num+1, node+2);//在node放置国王
}

int judge(int index1, int index2){//判断两种状态相邻时是否冲突
    if(situation[index1] & situation[index2]) return 0;
    if(situation[index1] & (situation[index2]<<1)) return 0;
    if((situation[index1]<<1) & situation[index2]) return 0;//只能用左移
    return 1;
}

void dp_search(){
    for(int j=1;j<=inx;j++) dp[1][j][count[j]]=1;//第一行放置国王
    for(int i=2;i<=n;i++){//从第二行开始
        for(int j=1;j<=inx;j++){
            for(int x=1;x<=inx;x++){
                if(!judge(j, x)) continue;
                for(int k=count[j];k<=m;k++) dp[i][j][k]+=dp[i-1][x][k-count[j]];
            }
        }
    }
}

void output(){
    long long int ans=0;
    for(int i=1;i<=inx;i++) ans+=dp[n][i][m];
    printf("%lld\n", ans);
}

int main(){
    scanf("%d %d", &n, &m);
    dfs(0, 0, 0);
    dp_search();
    output();
    return 0;
}