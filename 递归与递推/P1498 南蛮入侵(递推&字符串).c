#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char **output;
int n, h=2, w=4;

void print(int m){
    if(m>n) return;
    if(m==1){
        output[0][1]='/', output[0][2]='\\';
        output[1][0]='/', output[1][1]='_', output[1][2]='_', output[1][3]='\\';
    }
    else{
        for(int i=0;i<h;i++){
            for(int j=2*w-1;j>=h;j--){
                output[i][j]=output[i][j-h];
                output[i][j-h]=' ';
            }
        }
        for(int i=h;i<h*2;i++){
            for(int j=w-1;j>=0;j--) output[i][j]=output[i-h][j+h];
        }
        for(int i=h;i<h*2;i++){
            for(int j=2*w-1;j>=w;j--) output[i][j]=output[i][j-w];
        }
        h*=2, w*=2;
    }
    print(m+1);
}

int main(){
    scanf("%d", &n);
    output=(char**)malloc(sizeof(char*)*pow(2, n));
    for(int i=0;i<pow(2, n);i++) output[i]=(char*)malloc(sizeof(char)*(pow(2, n+1)+1));
    for(int i=0;i<pow(2, n);i++) for(int j=0;j<pow(2, n+1);j++) output[i][j]=' ';

    print(1);

    for(int i=0;i<pow(2, n);i++){
        for(int j=0;j<=pow(2, n)+i;j++){
            printf("%c", output[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<pow(2, n);i++) free(output[i]);
    free(output);
    return 0;
}