#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **arr;
int n;

void divide(int x, int y, int m){
    if (m != 1){
        for(int i = y; i < y + m / 2; i++) for(int j = x; j < x + m / 2; j++) arr[i][j] = 0;
        for(int i = y; i < y + m / 2; i++) for(int j = x + m / 2; j < x + m; j++) arr[i][j] = 1;
        for(int i = y + m / 2; i < y + m; i++) for(int j = x; j < x + m / 2; j++) arr[i][j] = 1;
        for(int i = y + m / 2; i < y + m; i++) for(int j = x + m / 2; j < x + m; j++) arr[i][j] = 1;
        divide(x + m / 2, y, m / 2);
        divide(x, y + m / 2, m / 2);
        divide(x + m / 2, y + m / 2, m / 2);
    }
}

int main(){
    scanf("%d", &n);
    int m = pow(2, n);
    arr = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++) arr[i] = (int*)malloc(m * sizeof(int));

    divide(0, 0, m);

    for (int i = 0; i < m; i++){
        for(int j = 0; j < m; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }

    for(int i = 0; i < m; i++) free(arr[i]);
    free(arr);
    return 0;
}