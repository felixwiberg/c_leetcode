#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int ascii[256] = {0};
    int length = 0;
    int longest = 0;
    for(int i = 0; i<strlen(s); i++){
        if(ascii[s[i]] == 0){
            length++;
            ascii[s[i]]++;
        }else{
            if(length>longest){
                longest=length;
            }
            if(length>1){
                i = i-(length-1);
            }
            memset(ascii, 0, sizeof ascii);
            ascii[s[i]]++;
            length = 1;
        }
    }
    if(length>longest){
        longest = length;
    }
    return longest;
}

int main(){
    char * s = "abcddefg";
    int p = lengthOfLongestSubstring(s);
    printf("The longest substring is %d", p);
    return 0;
}
