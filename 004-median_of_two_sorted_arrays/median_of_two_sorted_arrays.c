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
            if(i1>nums1Size-2){
                c1 = 2147483647;
            }else{
                i1++;
                c1 = nums1[i1];
            }
        }else if (c2<c1){
            current = c2;
            if(i2>nums2Size-2){
                c2 = 2147483647;
            }else{
                i2++;
                c2 = nums2[i2];
            }
        }else{
            if(i1<nums1Size-1){
                current = c1;
                i1++;
                c1 = nums1[i1];
            }else if(i2<nums2Size-1){
                current = c2;
                i2++;
                c2 = nums2[i2];
            }else{
                current = c1;
            }
        }
    }
    return odd?current:(current+prev)/2.0;
}

int main(){
    int nums1[] = {2,2};
    int nums2[] = {2,2,2,2,2,2,2,2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]); 
    int size2 = sizeof(nums2) / sizeof(nums2[0]); 
    double res = findMedianSortedArrays(nums1, size1, nums2, size2);
    printf("%5.3f", res);
    return 0;
}
