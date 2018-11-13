#include "iostream"
#include "binary_tree.h"
#include "queue"

class PathSum {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return false;
        }
        return val_sum(root, 0, sum);
    }
    bool val_sum(TreeNode* node, int curr_sum, int sum){
        curr_sum = node->val + curr_sum;
        if(curr_sum == sum && node->right == nullptr && node->left == nullptr)
            return true;
        else{
            if(node->left)
                if(val_sum(node->left, curr_sum, sum))
                    return true;
            if(node->right)
                if(val_sum(node->right, curr_sum, sum))
                    return true;
        }
        return false;
    }
};
