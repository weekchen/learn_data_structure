//
// Created by chenzhiji on 18-10-23.
//
#include "iostream"
#include "vector"
#include "queue"
#include "binary_tree.h"

using namespace std;

class LevelTraversal {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
            while(!q.empty()){
                vector<int> curr;
                int size = int(q.size());
                for(int i = 0; i < size; i++) {
                    curr.push_back(q.front()->val);
                    if(q.front()->left != NULL)
                        q.push(q.front()->left);
                    if(q.front()->right != NULL)
                        q.push(q.front()->right);
                    q.pop();
                }
                res.push_back(curr);
            }
        }
        return res;
    }
};
