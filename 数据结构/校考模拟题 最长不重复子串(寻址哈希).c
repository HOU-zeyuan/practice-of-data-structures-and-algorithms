#include <stdio.h>

#define MAX(a, b) ((b) > (a) ? (b) : (a))

int lengthOfLongestSubstring(char *s){
    int ans = 0, left = 0;
    int has[128] = {0};
    for (int right = 0; s[right]; right++){
        char c = s[right];
        while (has[c]){
            has[s[left]] = 0;
            left++;
        }
        has[c] = 1;
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}

int main(){
    char s[100];
    printf("Input a string: ");
    scanf("%s", s);
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}