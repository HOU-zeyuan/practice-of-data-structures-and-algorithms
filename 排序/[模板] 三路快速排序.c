#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int n;
long long int *arr;

void swap(long long int *a, long long int *b){
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

void three_way_quick_sort(long long int l, long long int r){
    if (l >= r) return;

    long long int left = l, right = r, pivot = arr[l + rand() % (r - l + 1)];
    long long int i = l;
    while (i <= right){
        if (arr[i] < pivot) swap(&arr[i++], &arr[left++]);
        else if (arr[i] > pivot) swap(&arr[i], &arr[right--]);
        else i++;    
    } 

    three_way_quick_sort(l, left - 1);
    three_way_quick_sort(right + 1, r);
}

int main(){
    srand((int)time(NULL));
    scanf("%lld", &n);
    arr = (long long int *)malloc(n * sizeof(long long int));
    for (long long int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    three_way_quick_sort(0, n - 1);

    for (long long int i = 0; i < n; i++){
        if (i != n - 1) printf("%lld ", arr[i]);
        else printf("%lld\n", arr[i]);
    }

    free(arr);
    return 0;
}
