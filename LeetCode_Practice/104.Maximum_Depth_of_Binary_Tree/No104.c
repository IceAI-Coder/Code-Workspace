#include <stdlib.h>

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

