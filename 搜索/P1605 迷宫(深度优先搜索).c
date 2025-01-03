#include <stdio.h>

int n, m, num, ans=0;
int c, d, e, f;
int arr[6][6];

void dfs(int x, int y){
    if(x==e && y==f){
        ans++;
        return;
    }
    int dx[]= {0, 0, 1, -1};
    int dy[]= {1, -1, 0, 0};
    for(int k=0; k<4; k++){
        int i=dx[k]+x, j=dy[k]+y;
        if(i>=1 && i<=n && j>=1 && j<=m && arr[i][j]==0){
            arr[i][j]=1;
            dfs(i, j);
            arr[i][j]=0;
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &num);
    scanf("%d %d %d %d", &c, &d, &e, &f);
    arr[c][d]=1;
    for(int i=0; i<num; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b]=1;
    }

    dfs(c, d);
    printf("%d", ans);
    return 0;
}