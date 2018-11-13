#include "iostream"
#include "queue"
#include "binary_tree.h"

using namespace std;

class MaximumDepth {
private:
    int maxdepth = 0;
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != NULL)
            q.push(root);
        else
            return 0;
        while(!q.empty()){
            int queue_size = q.size();
            for(int i = 0; i < queue_size; i++){
                if(q.front()->left != NULL)
                    q.push(q.front()->left);
                if(q.front()->right != NULL)
                    q.push(q.front()->right);
                q.pop();
            }
            maxdepth++;
        }
        return maxdepth;
    }
};
