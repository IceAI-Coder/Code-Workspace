// https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int idx1, idx2, ptr;
    idx1 = m-1;
    idx2 = n-1;
    ptr = m + n - 1;
    while(idx1 >=0 || idx2 >=0){
        if(idx1 < 0){
            nums1[ptr--] = nums2[idx2--];
        }
        else if(idx2 < 0){
            nums1[ptr--] = nums1[idx1--];
        }
        else if(nums1[idx1] > nums2[idx2]){
            nums1[ptr--] = nums1[idx1--];
        }
        else{
            nums1[ptr--] = nums2[idx2--];
        }
    }
}