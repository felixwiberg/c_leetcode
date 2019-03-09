#include <stdio.h>
#include <stdbool.h>

int reverse(int x) {
    bool negative = x<0?true:false;
    if(negative){
        x *+ -1;
    }
    int tmp, ret = 0;
    while(x>0){
        ret *= 10;
        tmp = x%10;
        ret += tmp;
        x /= 10;
        printf("%d\n", ret);
    }
    if(negative){
        x *= -1;
    }
    return ret;
}

int main(){
    int ret = reverse(657);
    printf("%d", ret);
    return 0;
}
