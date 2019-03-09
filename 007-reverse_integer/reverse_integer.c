#include <stdio.h>
#include <stdbool.h>

int reverse(int x) {
    bool negative = x<0?true:false;
    if(negative){
        x *+ -1;
    }
    long tmp, ret = 0;
    while(x>0){
        ret *= 10;
        tmp = x%10;
        ret += tmp;
        x /= 10;
    }
    if (ret > 2^31){
        return 0;
    }
    if(negative){
        x *= -1;
    }
    return ret;
}

int main(){
    //int ret = reverse(657);
    int ret = reverse(1534236469);
    printf("%d", ret);
    return 0;
}
