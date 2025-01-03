#include <stdio.h>

int n, ans=0;
int arr[6][6], permetation[6];

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int reverse_num(int *arr){
    int count=0;
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[j]>arr[i]) count++;
        }
    }
    return count;
}

void dfs(int x){
    if(x==n+1){
        int temp=1;
        for(int i=1; i<=n; i++) temp*=arr[i][permetation[i]];
        ans+=reverse_num(permetation)%2==0?temp:-temp;
        return;
    }
    for(int i=x; i<=n; i++){
        swap(&permetation[x], &permetation[i]);
        dfs(x+1);
        swap(&permetation[x], &permetation[i]);
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%d", &arr[i][j]);
    for(int i=1; i<=n; i++) permetation[i]=i;

    dfs(1);
    printf("%d\n", ans);
    return 0;
}