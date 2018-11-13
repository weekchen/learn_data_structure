//
// Created by chenzhiji on 18-11-13.
//

#ifndef DATA_STRUCT_BINARY_TREE_H
#define DATA_STRUCT_BINARY_TREE_H

#endif //DATA_STRUCT_BINARY_TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};