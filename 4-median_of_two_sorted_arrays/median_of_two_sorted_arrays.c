#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int midpoint = (nums1Size + nums2Size)/2;
    int odd = (nums1Size + nums2Size)%2;
    
    int i1 = 0, i2 = 0;
    double res = 0;
    int current = 0;
    int prev = 0;
    
    for(int i = 0; i <= midpoint; i++){
        prev = current;
        if(i2==nums2Size || nums1[i1] < nums2[i2]){
            current = nums1[i1];
            i1++;
        }else if(i1==nums1Size || nums2[i1] < nums1[i2]){
            current = nums2[i2];
            i2++;
        }else{
        }
        printf("%d ", prev);
        printf("%d \n",current);
    }
    if(odd){
        res = current;
    }else{
        res = (current+prev)/2.0;
    }
    return res;
}

int main(){
    int nums1[] = {1,2,3,4};
    int nums2[] = {0,40};
    double res = findMedianSortedArrays(nums1, 4, nums2, 2);
    printf("%5.3f", res);
    return 0;
}
