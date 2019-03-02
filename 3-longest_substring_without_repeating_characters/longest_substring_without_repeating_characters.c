#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int len = 0;
    char *end=s,*temp;
    char *addresses[256]={NULL};
    while(*end){
        //takes the element at ascii-value *end
        temp = addresses[*end];
        //stores the string end at ascii-value *end
        addresses[*end]=end;
        //if there is a collision
        if(temp>=s){
            len=end-s>len?end-s:len;
            s = temp+1;
        }
        end++;
    }
    len=end-s>len?end-s:len;
    return len;
}
int main(){
    char * s = "abcdefdklmn";
    int p = lengthOfLongestSubstring(s);
    printf("The longest substring is %d", p);
    return 0;
}
