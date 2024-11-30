#include <stdio.h>
#include <string.h>

int n, output[10], used[10];

void print(){
    for(int i=1;i<=n;i++){
        if(i!=n) printf("    %d", output[i]);
        else printf("    %d\n", output[i]);
    }
}

void dfs(int m){
    if(m>n){
        print();
        return;
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            output[m]=i;
            used[i]=1;
            dfs(m+1);
            used[i]=0;
        }
    }
}

int main(){
    scanf("%d", &n);
    memset(output, 0, sizeof(output));
    memset(used, 0, sizeof(used));
    dfs(1);
    return 0;
}