#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x) {
    int ret = 0;
    while(x!=0){
        if (abs(ret) > INT_MAX/10){return 0;}
        ret = ret*10 + x%10;
        x /= 10;
        printf("%d\n",ret);
    }
    return ret;
}

int main(){
    int ret = reverse(-657);
    //int ret = reverse(1534236469);
    //int ret = reverse(-2147483648);
    printf("%d", ret);
    return 0;
}
