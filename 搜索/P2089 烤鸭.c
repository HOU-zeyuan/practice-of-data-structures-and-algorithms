#include <stdio.h>
#include <stdlib.h>

int n, ans=0;
int arr[10]={0};
int **output;

void dfs(int num, int sum){
    if(sum>n) return;
    if(num==10){
        if(sum==n){
            for(int i=0; i<10; i++) output[ans][i]=arr[i];
            ans++;
        }
        return;
    }
    for(int i=1; i<=3; i++){
        arr[num]=i;
        dfs(num+1, sum+i);
    }
}

int main(){
    scanf("%d", &n);
    if(n<10 || n>30){
        printf("0\n");
        return 0;
    }

    output=(int**)malloc(sizeof(int*)*10000);
    for(int i=0; i<10000; i++) output[i]=(int*)malloc(sizeof(int)*10);

    dfs(0, 0);
    printf("%d\n", ans);
    for(int i=0; i<ans; i++){
        for(int j=0; j<10; j++){
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<10000; i++) free(output[i]);
    free(output);
    return 0;
}