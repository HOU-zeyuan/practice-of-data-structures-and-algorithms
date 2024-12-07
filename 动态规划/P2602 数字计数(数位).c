#include <stdio.h>
#include <math.h>

long long int a, b;
long long int dp[13]={0}, ans1[10]={0}, ans2[10]={0};

void solve(long long int n, long long int *arr){
    long long int temp=n, inx=0;
    int digit[13]={0};
    while(n) digit[++inx]=n%10, n/=10;

    for(int i=inx; i>=1; i--){
        for(int j=0; j<=9; j++) arr[j]+=dp[i-1]*digit[i];
        for(int j=0; j<digit[i]; j++) arr[j]+=pow(10, i-1);
        temp-=digit[i]*pow(10, i-1), arr[digit[i]]+=temp+1;//使temp为[pow(10, i-1), n]区间内剩余的数，加剩余最高位的数位出现次数
        arr[0]-=pow(10, i-1);//减去最左位前导零
    }
}

int main(){
    scanf("%lld%lld", &a, &b);

    dp[0]=0;
    for(int i=1; i<=12; i++) dp[i]=dp[i-1]*10+pow(10, i-1);//算上前导零，对于所有满i位数，各数位出现次数相同
                                                           //对于i位数，前i-1位数贡献dp[i-1]*10，第i位贡献pow(10, i-1)
    solve(b, ans1), solve(a-1, ans2);

    for(int i=0; i<=9; i++) printf("%lld ", ans1[i]-ans2[i]);
    return 0;
}