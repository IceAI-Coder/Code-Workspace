#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MIN_VALUE -1001;

int maxValue = MIN_VALUE;
int caculatePossibleMaxSum(struct TreeNode* root){
    if(root==NULL){
        return -1001;
    }
    else if(root->left == NULL & root->right == NULL){
        if(root->val > maxValue){
            maxValue = root->val;
        }
        return root->val;
    }
    else{
        int l = caculatePossibleMaxSum(root->left);
        int r = caculatePossibleMaxSum(root->right);

        if(l > maxValue){
            maxValue = l;
        }
        if(r > maxValue){
            maxValue = r;
        }
        if(root->val > maxValue){
            maxValue = root->val;
        }
        if(root->val + l > maxValue){
            maxValue = root->val + l;
        }
        if(root->val + r > maxValue){
            maxValue = root->val + r;
        }
        if(l + r + root->val > maxValue){
            maxValue = l + r + root->val;
        }

        // None
        // root
        // l + root
        // r + root
        // return root (to avoid any further case?)
        if(root->val + l < 0 && root->val + r < 0 && root->val < 0){
            return MIN_VALUE;
        }
        else if(l<=0 && r<=0){
            return root->val;
        }
        else if(l>=r && l>0){
            return root->val + l;
        }
        else if(r>l && r>0){
            return root->val + r;
        }
        else{
            return root->val;
        }
    }
}

int maxPathSum(struct TreeNode* root) {
    maxValue = -1001;
    caculatePossibleMaxSum(root);
    return maxValue;
}