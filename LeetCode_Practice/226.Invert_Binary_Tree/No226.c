#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *tmp;

    if(root==NULL){
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL){
        return root;
    }
    else{
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}