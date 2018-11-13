#include "iostream"
#include "stack"
#include "vector"
#include "binary_tree.h"

using namespace std;

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
