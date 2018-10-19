//
// Created by chenzhiji on 18-10-19.
//

/**
 * WOW!!!without visited[][], codes will be faster.
 */

#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class FloodFill {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        start_color = image[sr][sc];
        set_color = newColor;
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        if(start_color != set_color)
            setColor(image, sr, sc, visited);
        return image;
    }

private:
    int start_color;
    int set_color;
    vector<vector<int>> steps{{1,0},{-1,0},{0,1},{0,-1}};
    void setColor(vector<vector<int>>& image, int x, int y, vector<vector<bool>>& visited){
        if(x >= 0 && y >=0 && x < image.size() && y < image[0].size()){
            if(!visited[x][y] && image[x][y] == start_color){
                image[x][y] = set_color;
                visited[x][y] = true;
                for(auto step : steps){
                    setColor(image, x + step[0], y + step[1], visited);
                }
            }
        }
    }
};
