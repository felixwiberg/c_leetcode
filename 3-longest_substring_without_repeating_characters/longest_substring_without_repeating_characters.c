#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int ascii[256] = {0};
    int length = 0;
    int longest = 0;
    for(int i = 0; i<strlen(s); i++){
        if(ascii[(int)s[i]] == 0){
            length++;
            ascii[(int)s[i]]++;
        }else{
            if(length>longest){
                longest = length;
                length = 1;
                memset(ascii, 0, sizeof ascii);
                ascii[(int)s[i]]++;
            }
        }
    }
    if(length>longest){
        longest = length;
    }
    return longest;
}

int main(){
    char * s = "babb";
    int p = lengthOfLongestSubstring(s);
    printf("The longest substring is %d", p);
    return 0;
}