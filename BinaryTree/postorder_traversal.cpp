//
// Created by chenzhiji on 18-10-23.
//
#include "iostream"
#include "vector"
#include "binary_tree.h"

using namespace std;

class PostorderTraversal {
private:
    vector<int> res;

public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != NULL)
            check(root);
        return res;
    }

    void check(TreeNode* node){
        if(node->left != NULL)
            check(node->left);
        if(node->right != NULL)
            check(node->right);
        res.push_back(node->val);
    }
};
