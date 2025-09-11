#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    if(root->left != NULL && root->right != NULL){
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        if(x>y){
            return 1 + x;
        }
        else{
            return 1 + y;
        }
    }
    else if(root->left != NULL){
        return 1 + maxDepth(root->left);
    }
    else if(root->right != NULL){
        return 1 + maxDepth(root->right);
    }
    else{
        return 1;
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root==NULL){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
    queue[0] = root;

    int front = 0;
    int size = 1;
    int pre_size = 1;
    
    *returnSize = maxDepth(root);
    int **output = (int**)malloc(sizeof(int*)*(*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));

    for(int i=0; i<*returnSize; i++){
        // add new in queue first
        for(int j=0; j<pre_size; j++){
            if(queue[front+j]->left != NULL){
                queue[front+size] = queue[front+j]->left;
                size++;
            }
            if(queue[front+j]->right != NULL){
                queue[front+size] = queue[front+j]->right;
                size++;
            }
        }

        
        // add in output then remove from queue
        output[i] = (int*)malloc(sizeof(int)*pre_size);
        (*returnColumnSizes)[i] = pre_size;
        for(int j=0; j<pre_size; j++){
            output[i][j] = queue[front]->val;
            front++;
            size--;
        }
        pre_size = size;
    }
    free(queue);
    return output;
}


int main(){
    struct TreeNode input[5];

    input[0].val = 3;
    input[1].val = 9;
    input[2].val = 20;
    input[3].val = 15;
    input[4].val = 7;

    input[0].left = &input[1];
    input[0].right = &input[2];

    input[1].left = NULL;
    input[1].right = NULL;

    input[2].left = &input[3];
    input[2].right = &input[4];

    input[3].left = NULL;
    input[3].right = NULL;

    input[4].left = NULL;
    input[4].right = NULL;

    int returnSize;
    int *returnColumnSizes;
    int **output;
    output = levelOrder(input,&returnSize, &returnColumnSizes);

    return 0;
}