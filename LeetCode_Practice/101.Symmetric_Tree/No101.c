#include <stdlib.h>
#include <stdbool.h>

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
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL){
        return true;
    }
    else if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
        return false;
    }
    else if(p->val != q->val){
        return false;
    }
    else{
        return isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
    }
}
bool isSymmetric(struct TreeNode* root) {
    if(root == NULL){
        return true;
    }
    else if(root->left == NULL && root->right == NULL){
        return true;
    }
    else if(root->left != NULL && root->right != NULL){
        invertTree(root->right);
        return isSameTree(root->left, root->right);
    }
    else{
        return false;
    }
}