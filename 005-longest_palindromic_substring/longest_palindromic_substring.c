#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//jiijb
char* longestPalindrome(char* s){
    int a, b, length = 0, longest = 0, start = 0, end = 0, ind_left = 0, ind_right = 0;
    int string_length = strlen(s);
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
        printf("%c %c\n", a,b);
        while(a == b){
            if(length>longest){
                start = ind_left;
                end = ind_right;
                longest = length;
            }
            printf("       %c %c %d\n %d %d\n\n", a,b,longest, ind_left, ind_right);
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
    if(longest>0){
        char *to = (char*) malloc(longest);
        strncpy(to, s+start, longest);
        return to;
    }else{
        char *to = malloc(sizeof(char));
        *to = s[0];
        return to;
    }
}

int main(){
    char *s = "kkka";
    char *ret = longestPalindrome(s);
    printf("\n");
    printf("%s\n", ret);
    return 0;
}

