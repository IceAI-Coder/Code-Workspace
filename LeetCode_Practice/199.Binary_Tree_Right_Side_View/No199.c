#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL){
        return NULL;
    }
    
    // bfs
    // alwasy find right value if have
    
    struct TreeNode *queue[100];
    int front = 0;
    int size = 1;
    queue[0] = root;

    int* ans = (int*)malloc(sizeof(int)*100);
    while(size > 0){
        ans[(*returnSize)++] = queue[front + size - 1]->val;

        int ptr = front + size;
        for(int i=0; i<size; i++){
            if(queue[front + i]->left != NULL){
                queue[ptr++] = queue[front + i]->left;
            }
            if(queue[front + i]->right != NULL){
                queue[ptr++] = queue[front + i]->right;
            }
        }

        front += size;
        size = ptr - front;
    }
    return ans;
}