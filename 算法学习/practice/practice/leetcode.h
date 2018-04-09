#include <iostream>
#include <string>

#include "tree.h"
TreeNode* findLeft(TreeNode* root);
TreeNode* findRight(TreeNode* root);


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if( root == NULL || p == NULL || q == NULL)
        return NULL;
    if( (p->val >= root->val && q->val <= root->val) || (p->val <= root->val && q->val >= root->val))
        return root;
    else if(p->val >= root->val && q->val >= root->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return lowestCommonAncestor(root->right, p, q);
}

bool isValidBST(TreeNode* root) {
    if(root == NULL)
        return true;

    if( root ->left == NULL && root->right == NULL)
        return true;
    TreeNode* left = findLeft(root->left);
    TreeNode* right = findRight(root->right);
    if(left == NULL && right == NULL)
        return true;
	else if(left == NULL){
		if(right->val <= root->val)
            return false;	
	}
	else if(right == NULL){
        if(left->val >= root->val)
            return false;	
	}
	else{
        if( left->val >= root->val || right->val <= root->val)
            return false;	
	}
    return isValidBST(root->left) && isValidBST(root->right);
}
TreeNode* findLeft(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    if(root->right)
        return findLeft(root->right);
    return root;
}
TreeNode* findRight(TreeNode* root){
    if(root == NULL)
        return NULL;
    if(root->left)
        return findRight(root->left);
    return root;
}


