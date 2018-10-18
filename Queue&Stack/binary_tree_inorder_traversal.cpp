//
// Created by chenzhiji on 18-10-18.
//
#include "iostream"
#include "stack"
#include "vector"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class InorderTraversal {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root !=NULL)
            getval(root);
        return result;
    }

private:
    vector<int> result;
    stack<TreeNode> s;
    void getval(TreeNode* root){
        s.push(*root);
        if (s.top().left != NULL)
            getval(s.top().left);
        result.push_back(s.top().val);
        if (s.top().right != NULL)
            getval(s.top().right);
        s.pop();
    }
};
