#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int midpoint = (nums1Size + nums2Size)/2;
    int odd = (nums1Size + nums2Size)%2; 
    int i1 = 0, 
        i2 = 0,
        current = 0,
        prev = 0;

    if(nums1Size == 0){
            return odd?nums2[midpoint]:(nums2[midpoint]+nums2[midpoint-1])/2.0;
    }
    if(nums2Size == 0){
            return odd?nums1[midpoint]:(nums1[midpoint]+nums1[midpoint-1])/2.0;
    }

    int c1 = nums1[0],
        c2 = nums2[0];

    for(int i = 0; i <= midpoint; i++){
        prev = current;
        if(c1<c2){
            current = c1;
            if(i1>nums1Size-1){
                c1 = 10000;
            }else{
                c1 = nums1[++i1];
            }
        }else{
            current = c2;
            if(i2>nums2Size-1){
                c2 = 10000;
            }else{
                c2 = nums2[++i2];
            }
        }
        printf("%d %d\n", prev, current);
    }
    return odd?current:(current+prev)/2.0;
}

int main(){
    int nums1[] = {};
    int nums2[] = {1,2,2};
    double res = findMedianSortedArrays(nums1, 0, nums2, 3);
    printf("%5.3f", res);
    return 0;
}
