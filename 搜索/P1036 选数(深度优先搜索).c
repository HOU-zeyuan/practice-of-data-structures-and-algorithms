#include <stdio.h>
#include <math.h>

int n, m, ans;
long long int arr[25];

int is_prime(int n){
    if (n <= 1) return 0;
    else if (n == 2) return 1;
    else if (n % 2 == 0) return 0;
    else{
        for (int i = 3; i <= sqrt(n); i += 2){
            if (n % i == 0) return 0;
        }
        return 1;
    }
}

void depth_first_search(int num, int sum, int node){
    if (num == m){
        if (is_prime(sum)){
            ans++;
            return;
        }
    }
    for (int i = node; i < n; i++) depth_first_search(num + 1, sum + arr[i], i + 1);
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    depth_first_search(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
