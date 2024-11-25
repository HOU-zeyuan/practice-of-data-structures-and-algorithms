#include <stdio.h>
#include <stdlib.h>

int size, sum=0;
int *column, *diag1, *diag2; // diag1: 左上到右下对角线, diag2: 右上到左下对角线
int *ans;

void queen(int i){
    if(i>size){
        sum++;

        if(sum<=3){
            for (int j=1; j<=size; j++){
                if(j<size) printf("%d ", ans[j]);
                else printf("%d\n", ans[j]);
            }
        }
        return;
    }

    for (int j=1; j<=size; j++){
        if (!column[j] && !diag1[i-j+size] && !diag2[i+j]){ // i-j为定值，+size是为了防止负数；i+j为定值
            ans[i]=j;
            column[j]=1, diag1[i-j+size]=1, diag2[i+j]=1;

            queen(i + 1);

            column[j]=0, diag1[i-j+size]=0, diag2[i+j]=0;
        }
    }
}

int main(){
    scanf("%d", &size);
    column=(int *)calloc(size+1, sizeof(int));
    diag1=(int *)calloc(2*size+1, sizeof(int)); 
    diag2=(int *)calloc(2*size+1, sizeof(int)); 
    ans=(int *)malloc(sizeof(int)*(size+1));

    queen(1);

    printf("%d", sum); 
    free(column);
    free(diag1);
    free(diag2);
    free(ans);
    return 0;
}
