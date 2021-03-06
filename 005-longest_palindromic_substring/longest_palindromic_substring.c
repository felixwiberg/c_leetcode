#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//jiijb
char* longestPalindrome(char* s){
    int a, b, length = 0, longest = 0, start = 0, ind_left = 0, ind_right = 0;
    int string_length = strlen(s);
    printf("%s\n", s);
    if(string_length == 0){ return ""; }
    if(string_length == 1){ return s; }
    if(string_length == 2 && s[0] == s[1]){ return s; }
    for(int i = 1; i<strlen(s)*2-1; i++){
        length = 0;
        if(i%2){
            ind_left = i/2;
            ind_right = i/2;
            length = 1;
        }else{
            ind_left = i/2;
            ind_right = i/2-1;
        }
        b = s[ind_left];
        a = s[ind_right];
        while(a == b){
            if(length>longest){
                start = ind_left;
                longest = length;
            }
            if(ind_left > 0 && ind_right<string_length){
                ind_left--;
                ind_right++;
                a = s[ind_right];
                b = s[ind_left];
                length+=2;
            }else{
                a = 1;
                b = 2;
                break;
            }
        }
    }
    char* res = malloc(longest+1);
    memcpy(res, s+start, longest);
    res[longest] = '\0';
    return res;
}

int main(){
    char *s = "asd";
    char *ret = longestPalindrome(s);
    printf("%s\n", ret);
    return 0;
}

