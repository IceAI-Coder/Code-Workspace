#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL){
        return false;
    }
    else if(root->left==NULL && root->right==NULL){
        if(root->val == targetSum){
            return true;
        }
        else{
            return false;
        }
    }
    else if(root->left != NULL && root->left != NULL){
        targetSum-=root->val;
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
    else if(root->left != NULL){
        targetSum-=root->val;
        return hasPathSum(root->left, targetSum);
    }
    else{
        targetSum-=root->val;
        return hasPathSum(root->right, targetSum);
    }
}