//
// Created by weekchen on 18-10-14.
//
#include "iostream"
#include "vector"
#include "stack"
#include "unordered_set"

using namespace std;

typedef struct {
    int x;
    int y;
}node;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<vector<char>> s;
        unordered_set<node> unvisited;
        vector<vector<int>> steps = {{0,1},{0,-1},{1,0},{-1,0}};
        node current_node, next;
        int count;
        for(int i=0; i<grid.size();i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == 1)
                    current_node.x = i;
                    current_node.y = j;
                    unvisited.emplace(current_node);
            }
        }
        s.push(unvisited.begin());
        while(!unvisited.empty()){
            current_node = s.top();
            for(int i=0; i < steps.size();i++){}

        }
    }
};