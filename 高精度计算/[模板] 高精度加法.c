#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *add(char *num1, char *num2){
    int len1 = strlen(num1), len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;

    char *result = (char *)calloc(maxLen + 2, sizeof(char)); // +2 to handle carry and '\0'
    for (int i = 0; i < maxLen + 2; i++) result[i] = '0';

    int carry = 0;                                              // 进位
    int index = maxLen;                                         // 从字符串的末尾开始
    result[index + 1] = '\0'; // 添加字符串结束符

    // 逐位相加
    for (int i = 0; i < maxLen || carry; i++){
        int digit1 = i < len1 ? num1[len1 - i - 1] - '0' : 0;
        int digit2 = i < len2 ? num2[len2 - i - 1] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[index--] = (sum % 10) + '0';
    }

    // 如果还有进位
    if (index == 0 && carry){
        result[index] = carry + '0';
        return result;
    }
    else return result + index + 1;
}

int main(){
    char *num1 = (char *)malloc(500 * sizeof(char));
    char *num2 = (char *)malloc(500 * sizeof(char));
    fgets(num1, 500, stdin);
    fgets(num2, 500, stdin);
    num1[strcspn(num1, "\n")] = 0; // 去除换行符
    num2[strcspn(num2, "\n")] = 0; // 去除换行符

    char *result = add(num1, num2);
    printf("%s\n", result);

    free(num1);
    free(num2);
    // 注意：不要释放 result，因为返回值可能是一个偏移指针
    return 0;
}
