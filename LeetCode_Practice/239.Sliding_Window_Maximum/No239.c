#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* output = (int*)malloc(sizeof(int)*(*returnSize));
    
    // Use queue with nums only
    int front = -1;
    int rear = -1;  // if front==rear, queue is empty


    // To keep the max in the front of queue
    // When new value comes, 
    // (1) New value bigger or equal then front of queue, empty queue then store only new value
    // (2) Else
    //      (a) If new value idx - front value idx <= k   ==> no need to dequeue, still keep max in front
    //      (b) Else find the max and put to the front of queue
    
    // To init the queue, store k items in the queue
    // Find the max then store in the front
    int max_idx = 0;
    for (int i=1; i<k; i++){
        if(nums[i] >= nums[max_idx]){
            max_idx = i;
        }
    }
    front = max_idx-1;
    rear = k-1;
    output[0] = nums[max_idx];

    int max;
    // When new value comes, 
    for (int i=k; i<numsSize; i++){
        rear++;
        // (1) New value bigger or equal then front of queue, empty queue then store only new value
        if(nums[i] >= nums[front+1]){
            max = nums[i];
            front = rear - 1;
        }
        else{
            // (a) If new value idx - front value idx <= k   ==> no need to dequeue, still keep max in front
            if(rear - front <= k){
                max = nums[front+1];
            }
            // (b) Else find the max and put to the front of queue
            else{
                front++;
                max_idx = front+1;
                for(int j=front+2; j<=rear; j++){
                    if(nums[j] >= nums[max_idx]){
                        max_idx = j;
                    }
                }
                front = max_idx-1;
                max = nums[max_idx];
            }
        }
        output[i-k+1] = max;
    }
    return output;
}


int main(){
    int nums_1[8] = {1,3,-1,-3,5,3,6,7};
    int returnSize = 0;
    int* output_nums1 = maxSlidingWindow(nums_1, 8, 3, &returnSize);
    printf("[");
    for(int i=0; i<returnSize; i++){
        printf("%d", output_nums1[i]);
        if(i!=returnSize-1){
            printf(", ");
        }
    }
    printf("]\n");

    int nums_2[1] = {1};
    int* output_nums2 = maxSlidingWindow(nums_2, 1, 1, &returnSize);
    printf("[");
    for(int i=0; i<returnSize; i++){
        printf("%d", output_nums2[i]);
        if(i!=returnSize-1){
            printf(", ");
        }
    }
    printf("]\n");

    free(output_nums1);
    free(output_nums2);
    return 0;
}