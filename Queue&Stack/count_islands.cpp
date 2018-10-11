//
// Created by chenzhiji on 18-10-8.
//

/*
 * form leetcode.com
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 */

#include "iostream"
#include "queue"
#include "vector"

using namespace std;

/*
 * trash written by weekchen
 */

//
//typedef struct {
//    int x;
//    int y;
//    bool visited;
//}pointPos;
//
//class Solution {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        int num = 0;
//        int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//        queue<pointPos> q;
//        vector<pointPos> unvisited;
//        pointPos now_point, next_point;
//        int i,j;
//        now_point.visited = false;
//        next_point.visited = false;
//        for(i=0; i<grid.size(); i++) {
//            for (j = 0; j < grid[0].size(); j++) {
//                if (grid[i][j] == '1') {
//                    now_point.x = i;
//                    now_point.y = j;
//                    unvisited.push_back(now_point);
//                }
//            }
//        }
//        if(!unvisited.empty()) {
//            now_point.x = unvisited[0].x;
//            now_point.y = unvisited[0].y;
//            unvisited[0].visited = true;
//            q.push(now_point);
//        }
//        else
//            return num;
//        int flg=1;
//        while(flg){
//            for(i = 0; i < 4; i++)
//            {
//                next_point.x = now_point.x + step[i][0];
//                next_point.y = now_point.y + step[i][1];
//                if(next_point.x >= 0 && next_point.x < grid.size() && next_point.y >= 0 && next_point.y < grid[0].size()){
//                    if(grid[next_point.x][next_point.y] == '1') {
//                        for(j = 0; j<unvisited.size();j++) {
//                            if(next_point.x == unvisited[j].x && next_point.y == unvisited[j].y && !unvisited[j].visited){
//                                unvisited[j].visited = true;
//                                q.push(next_point);
//                                break;
//                            }
//                        }
//                    }
//                }
//            }
//            q.pop();
//            if(!q.empty()) {
//                now_point.x = q.front().x;
//                now_point.y = q.front().y;
//            }
//            else {
//                num += 1;
//                flg = 0;
//                for(i = 0;i < unvisited.size();i++){
//                    if(!unvisited[i].visited) {
//                        now_point.x = unvisited[i].x;
//                        now_point.y = unvisited[i].y;
//                        unvisited[i].visited = true;
//                        q.push(now_point);
//                        flg = 1;
//                        break;
//                    }
//                }
//
//            }
//        }
//        return num;
//    }
//};

/*
 * WoW!!!
 * so beautiful codes
 */

class Count_Islands {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int res = 0, row = grid.size(), col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1') {
                    res++;
                    set_zero(grid, i, j);
                }
            }
        }

        return res;
    }

    void set_zero(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        //left
        set_zero(grid, i, j-1);
        //right
        set_zero(grid, i, j+1);
        //down
        set_zero(grid, i+1, j);
        //up
        set_zero(grid, i-1, j);
    }

};