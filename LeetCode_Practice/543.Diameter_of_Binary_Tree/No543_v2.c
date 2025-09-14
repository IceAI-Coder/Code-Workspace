#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDiameter = 0;

int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int x = maxDepth(root->left);
    int y = maxDepth(root->right);
    if(x+y > maxDiameter){
        maxDiameter = x + y;
    }

    if(x>y){
        return 1 + x;
    }
    else{
        return 1 + y;
    }
    
}

int diameterOfBinaryTree(struct TreeNode* root) {
    maxDiameter = 0;
    maxDepth(root);
    return maxDiameter;
}