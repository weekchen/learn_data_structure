//
// Created by chenzhiji on 18-10-19.
//
/**
 *
 * DFS Time Limit Exceeded
 * 37 / 48 test cases passed.
 * TODO: while point's next four points are visited in this recursion, it cannot be given a correct distance.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(int i=0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] != 0){
                    vector<vector<bool>> visited1(matrix.size(), vector<bool>(matrix[0].size(), false));
                    findZero(matrix, i, j, visited, visited1);
                }
            }
        }
        for(auto i : matrix) {
            for (auto j : i)
                cout << j << "  ";
            cout << endl;
        }
        return matrix;
    }

private:
    vector<vector<int>> steps{{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> points;

    void findZero(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& visited, vector<vector<bool>>& visited1){
        vector<int> num(4, 0);
        vector<int> num1;
        visited1[x][y] = true;
        for(int i =0; i < steps.size(); i++){
            int x1 = x + steps[i][1];
            int y1 = y + steps[i][0];
            if(x1 >= 0 && x1 < matrix.size() && y1 >= 0 && y1 < matrix[0].size()) {
                if (matrix[x1][y1] == 0) {
                    matrix[x][y] = 1;
                    visited[x][y] = true;
                    return;
                } else if (visited[x1][y1]) {
                    num[i] = matrix[x1][y1] + 1;
                } else if (!visited1[x1][y1]){
                    findZero(matrix, x1, y1, visited, visited1);
                    num[i] = matrix[x1][y1] + 1;
                } else{
                }
            }
        }
        int k = 999999;
        for(int j = 0; j < 4; j++) {
            if (num[j] < k && num[j]!=0)
                k = num[j];
        }
        matrix[x][y] = k;
        visited[x][y] = true;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix{{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
                               {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
                               {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
                               {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
                               {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
                               {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
                               {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                               {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                               {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};
    auto k = s.updateMatrix(matrix);
}