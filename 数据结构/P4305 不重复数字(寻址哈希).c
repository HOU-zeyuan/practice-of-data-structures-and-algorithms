#include <stdio.h>
#include <string.h>

long long hash[1000000], random=969696, mod=1000000;

long long Hash(long long x){
    x%=random, x+=random;
    return x%random;
}

long long locate(long long x){//寻址函数
    long long y=Hash(x), i;
    for(i=0; i<mod && hash[(y+i)%mod]!=-1 && hash[(y+i)%mod]!=x; i++);//直到hash值为-1或x
    return (y+i)%mod;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(hash, -1, sizeof(hash));//防止0重复输出，故初始化为-1
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            long long x;
            scanf("%lld", &x);
            long long pos=locate(x);
            if(hash[pos]==-1){
                hash[pos]=x;
                printf("%lld ", x);
            }
        }
        printf("\n");
    }
    return 0;
}