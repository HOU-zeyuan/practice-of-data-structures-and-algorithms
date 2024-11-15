#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *multiple(char *num1, char *num2){
    int len1 = strlen(num1), len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) return "0";

    // Allocate result array and initialize to 0
    char *result = (char *)calloc(len1 + len2 + 1, sizeof(char));
    for (int i = 0; i < len1 + len2; i++) result[i] = '0';

    // Perform multiplication
    for (int i = len1 - 1; i >= 0; i--){
        for (int j = len2 - 1; j >= 0; j--){
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = (result[i + j + 1] - '0') + product;
            result[i + j + 1] = (sum % 10) + '0';
            result[i + j] += (sum / 10);
        }
    }

    // Remove leading zeros
    int index = 0;
    while (index < len1 + len2 && result[index] == '0') index++;
    if (index == len1 + len2) return "0"; // If all are zeros

    // Return the result without leading zeros
    return result + index;
}

int main(){
    char *num1 = (char *)malloc(500 * sizeof(char));
    char *num2 = (char *)malloc(500 * sizeof(char));
    fgets(num1, 500, stdin);
    fgets(num2, 500, stdin);
    num1[strcspn(num1, "\n")] = 0; 
    num2[strcspn(num2, "\n")] = 0; 

    char *result = multiple(num1, num2);
    printf("%s\n", result);

    free(num1);
    free(num2);
    return 0;
}
