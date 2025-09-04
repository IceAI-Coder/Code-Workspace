#include <stdio.h>

// No idea so directly implement the solution

void swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    k = numsSize - k;
    
    // seperate left side and right side
    // left => 0 to k -1
    // right => k to numsSize - 1

    // to reverse first
    // 1 2 3 4     5 6 7
    // 4 3 2 1     7 6 5
    int l, r;
    l = 0;
    r = k - 1;
    while(l<r){
        swap(&nums[l], &nums[r]);
        l++;
        r--;
    }
    l = k;
    r = numsSize - 1;
    while(l<r){
        swap(&nums[l], &nums[r]);
        l++;
        r--;
    }

    // to swap next
    // 4 3 2 1   7 6 5
    // ^             ^
    // 5 3 2 1   7 5 4
    l = 0;
    r = numsSize - 1;
    while(l<r){
        swap(&nums[l], &nums[r]);
        l++;
        r--;
    }
}

int main(){
    int x[7] = {1, 2, 3, 4, 5, 6 ,7};

    rotate(x, 7, 3);
    for(int i=0; i<7; i++){
        printf("%d, ", x[i]);
    }
    printf("\n");
    return 0;
}