//
// Created by chenzhiji on 18-11-13.
//
#include "iostream"
#include "vector"
#include "binary_tree.h"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        long size = inorder.size();
        if(size == 0)
            return nullptr;
        int j = 0;
        vector<TreeNode*> v;
        for(int i = 0; i < size; i++){
            if(inorder[i] != postorder[i]){
                j = i;
                TreeNode node(inorder[i]);
                v.push_back(&node);
                i++;
            }
            else
                j++;
        }
    }
};
