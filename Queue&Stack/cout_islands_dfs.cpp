//
// Created by weekchen on 18-10-14.
//
#include "iostream"
#include "vector"
#include "stack"
#include "unordered_set"
#include "algorithm"

using namespace std;

/**
 * my answer
 */

struct node {
    int x;
    int y;
    bool operator ==(const node &p)const {
        return(this->x == p.x && this->y == p.y);
    }
};


class CountIslandsDFS {
public:
    int numIslands(vector<vector<char>>& grid) {
        node current_node;
        int count = 0;
        for(int i=0; i<grid.size();i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    current_node.x = i;
                    current_node.y = j;
                    unvisited.push_back(current_node);
                }
            }
        }
        while(!unvisited.empty()){
            dfs(unvisited.front(), grid);
            cout<< unvisited.size()<< endl;
            count++;
        }
        return count;
    }

private:
    vector<node> unvisited;
    vector<vector<int>> steps = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(node curr, vector<vector<char>>& grid){
        node next;
        for(int i=0;i< steps.size();i++){
            next.x = curr.x + steps[i][0];
            next.y = curr.y + steps[i][1];
            if(next.x >= 0 && next.y >=0 && next.x < grid.size() && next.y < grid[0].size() && grid[next.x][next.y] == '1'){
                auto iter = find(unvisited.begin(),unvisited.end(),next);
                if(iter != unvisited.end()){
                    unvisited.erase(iter);
                    dfs(next, grid);
                }
            }
        }
        auto iter1 = find(unvisited.begin(),unvisited.end(),curr);
        if(iter1 != unvisited.end())
            unvisited.erase(iter1);
    }
};
/**
 * nice sample
 */

//class Solution {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        if (grid.empty()) return 0;
//        int m = grid.size(), n = grid[0].size(), num = 0;
//        vector<vector<bool>> visited(m, vector<bool> (n, false));
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == '1' && !visited[i][j]) {
//                    num++;
//                    markIslands(grid, visited, i, j);
//                }
//            }
//        }
//        return num;
//    }
//private:
//    void markIslands(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
//        visited[r][c] = true;
//        int m = grid.size(), n = grid[0].size();
//        if (r - 1 >= 0 && grid[r - 1][c] == '1' && !visited[r - 1][c])
//            markIslands(grid, visited, r - 1, c);
//        if (r + 1 < m && grid[r + 1][c] == '1' && !visited[r + 1][c])
//            markIslands(grid, visited, r + 1, c);
//        if (c - 1 >= 0 && grid[r][c - 1] == '1' && !visited[r][c - 1])
//            markIslands(grid, visited, r, c - 1);
//        if (c + 1 < n && grid[r][c + 1] == '1' && !visited[r][c + 1])
//            markIslands(grid, visited, r, c + 1);
//    }
//};

int main(){
    CountIslandsDFS s;
    vector<vector<char>> g{{'1','1','0','0','0'},
                              {'1','1','0','0','0'},
                              {'0','0','1','0','0'},
                              {'0','0','0','1','1'}};
    s.numIslands(g);
}