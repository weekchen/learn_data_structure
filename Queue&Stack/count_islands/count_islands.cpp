//
// Created by chenzhiji on 18-10-8.
//
#include "iostream"
#include "queue"

using namespace std;

typedef struct {
    int x;
    int y;
}pointPos;

class Solution {
private:
    int num = 0;
    int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    queue<pointPos> q;
    vector<pointPos> unvisited;
public:
    int numIslands(vector<vector<char>>& grid) {
        pointPos now_point, next_point;
        int i,j;
        for(i=0; i<grid.size(); i++) {
            for (j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    now_point.x = i;
                    now_point.y = j;
                    unvisited.push_back(now_point);
                }
            }
        }
        now_point.x = unvisited.begin().operator*().x;
        now_point.y = unvisited.begin().operator*().y;
        q.push(now_point);
        unvisited.erase(unvisited.begin());
        while(!unvisited.empty()){
            for(i = 0; i < 4; i++)
            {
                next_point.x = now_point.x + step[0][0];
                next_point.y = now_point.y + step[0][1];
                if(next_point.x >= 0 && next_point.x < grid.size() && next_point.y >= 0 && next_point.y < grid[0].size()){
                    if(grid[next_point.x][next_point.y] == 1) {
                        q.push(next_point);
                        for(i = 0; i<unvisited.size();i++)
                        {
                            if(unvisited.begin().operator*().x == next_point.x && unvisited[i].y == next_point.y) {
                                if(i == unvisited.size() - 1) {
                                    unvisited.erase(unvisited.begin() + i);
                                    unvisited.end() = unvisited.begin();
                                }
                            }
                        }
                    }
                }
            }
            q.pop();
            if(!q.empty()) {
                now_point.x = q.front().x;
                next_point.x = q.front().y;
            }
            else {
                num += 1;
                if(!unvisited.empty()) {
                    now_point.x = unvisited.begin().operator*().x;
                    now_point.y = unvisited.begin().operator*().y;
                }
            }
        }
        return num;
    }
};