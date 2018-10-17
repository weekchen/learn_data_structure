//
// Created by chenzhiji on 18-10-17.
//
#include "iostream"
#include "vector"
#include "stack"
#include "unordered_map"

using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        UndirectedGraphNode* ret = dfs(node);
        return ret;
    }
private:
    unordered_map<int,UndirectedGraphNode*> visited;
    UndirectedGraphNode* dfs(UndirectedGraphNode* s){
        UndirectedGraphNode* new_node;
        if(visited.find(s->label) == visited.end()){
            new_node = new UndirectedGraphNode(s->label);
            visited.insert(unordered_map<int,UndirectedGraphNode*>::value_type(s->label, new_node));
            for(int i=0;i<s->neighbors.size();i++)
                new_node->neighbors.push_back(dfs(s->neighbors[i]));
        }
        else{
            new_node = visited[s->label];
        }
        return new_node;
    }
};

