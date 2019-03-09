#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int reverse(int x) {
    bool negative = x<0?true:false;
    int tmp = 0;
    int ret = 0;
    while(x!=0){
        if (abs(ret) > 2147483648/10){
            return 0;
        }
        ret *= 10;
        tmp = x%10;
        ret += tmp;
        x /= 10;
    }
    if(negative){
        ret *= -1;
    }
    return (int)ret;
}

int main(){
    //int ret = reverse(657);
    //int ret = reverse(1534236469);
    int ret = reverse(-2147483648);
    printf("%d", ret);
    return 0;
}
