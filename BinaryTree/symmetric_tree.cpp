#include "iostream"
#include "deque"
#include "binary_tree.h"

using namespace std;

class IsSymmetric {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> q;
        if(root == nullptr)
            return true;
        q.push_back(root);
        while(!q.empty()){
            long queue_size = q.size();
            deque<TreeNode*> curr_q;
            for(int i = 0; i < queue_size; i++){
                if(q.front()->left)
                    q.push_back(q.front()->left);
                curr_q.push_back(q.front()->left);
                curr_q.push_back(q.front()->right);
                if(q.front()->right)
                    q.push_back(q.front()->right);
                q.pop_front();
            }
            while(!curr_q.empty()){
                if(curr_q.front() == nullptr ^ curr_q.back() == nullptr)
                    return false;
                else if(curr_q.front() != nullptr){
                    if(curr_q.front()->val != curr_q.back()->val)
                        return false;
                }
                curr_q.pop_front();
                curr_q.pop_back();
            }
        }
        return true;
    }
};

