//
// Created by chenzhiji on 18-10-23.
//
#include "iostream"
#include "vector"
#include "stack"
#include "binary_tree.h"

using namespace std;

class PreorderTraversal {
private:
    vector<int> res;

public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL)
            check(root);
        return res;
    }

    void check(TreeNode* node){
        TreeNode* curr = node;
        res.push_back(curr->val);
        if(curr->left != NULL)
            preorderTraversal(curr->left);
        if(curr->right != NULL)
            preorderTraversal(curr->right);
    }
};