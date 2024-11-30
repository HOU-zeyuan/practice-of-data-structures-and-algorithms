#include <stdio.h>
#include <stdlib.h>

int **arr, **translate;
int n, m, ans=0;

int min(int a, int b, int c){
    if(a<b){
        if(a<c) return a;
        else return c;
    }
    else{
        if(b<c) return b;
        else return c;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    arr=(int**)malloc(sizeof(int*)*(n+1));
    translate=(int**)malloc(sizeof(int*)*(n+1));
    for(int i=0;i<=n;i++){
        arr[i]=(int*)malloc(sizeof(int)*(m+1));
        translate[i]=(int*)malloc(sizeof(int)*(m+1));
        for(int j=0;j<=m;j++) translate[i][j]=0;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &arr[i][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]==1){
                translate[i][j]=min(translate[i-1][j], translate[i][j-1], translate[i-1][j-1])+1;
                ans=ans>=translate[i][j]?ans:translate[i][j];
            }
        }
    }

    printf("%d\n", ans);
    for(int i=0;i<=n;i++) free(arr[i]), free(translate[i]);
    free(arr), free(translate);
    return 0;
}