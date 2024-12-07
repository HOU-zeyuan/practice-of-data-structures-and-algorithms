#include <stdio.h>
#include <stdlib.h>

int n, m, ans=0;
int **arr;

void init(){
    scanf("%d %d", &n, &m);
    arr=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        arr[i]=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++) arr[i][j]=0;
    }
}

int is_valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n);
}

void dfs(int num, int start){
    if(num>m){
        ans++;
        return;
    }

    for(int pos=start;pos<n*n;pos++){
        int i=pos/n, j=pos%n;
        if(arr[i][j]==0){
            for(int x=i-1;x<=i+1;x++){
                for(int y=j-1;y<=j+1;y++){
                    if(is_valid(x, y)) arr[x][y]+=1;
                }
            }       
            dfs(num+1, pos+1);
            for(int x=i-1;x<=i+1;x++){
                for(int y=j-1;y<=j+1;y++){
                    if(is_valid(x, y)) arr[x][y]-=1;
                }
            }
        }
    }
}


int main(){
    init();
    dfs(1, 0);
    printf("%d\n", ans);

    for(int i=0;i<n;i++) free(arr[i]);
    free(arr);
    return 0;
}