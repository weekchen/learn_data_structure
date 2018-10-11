//
// Created by chenzhiji on 18-10-9.
//

/*
 *  You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.
 *  The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
 *  The lock initially starts at '0000', a string representing the state of the 4 wheels.
 *  You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
 *  Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
 **/

#include "iostream"
#include "vector"
#include "cmath"
#include "string"
#include "queue"
#include "unordered_set"

using namespace std;
/**
 * trash
 */
//typedef struct{
//    int x;
//    int y;
//    int f;
//    int g;
//    int h;
//}node;
//
//typedef struct{
//    int x;
//    int y;
//}wall;
//
//class Solution {
//public:
//    int openLock(vector<string>& deadends, string target) {
//        int i, j, target_x, target_y, min_f, min_index;
//        int step[8][4] = {{1,  0,  0,  0},
//                          {-1, 0,  0,  0},
//                          {0,  1,  0,  0},
//                          {0,  -1, 0,  0},
//                          {0,  0,  1,  0},
//                          {0,  0,  -1, 0},
//                          {0,  0,  0,  1},
//                          {0,  0,  0,  -1}};
//        vector<node> open, closed;
//        node current_node, next_node;
//        string lock = "0000";
//        vector<wall> walls;
//        wall a_wall;
//        for (i = 0; i < deadends.size(); i++) {
//            a_wall.x = (deadends[i][0] - '0') * 10 + (deadends[i][1] - '0');
//            a_wall.y = (deadends[i][2] - '0') * 10 + (deadends[i][3] - '0');
//            walls.push_back(a_wall);
//        }
//        target_x = (target[0] - '0') * 10 + target[1] - '0';
//        target_y = (target[2] - '0') * 10 + target[3] - '0';
//        current_node.x = 0;
//        current_node.y = 0;
//        current_node.g = 0;
//        current_node.h = target_x / 10 + target_x % 10 + target_y / 10 + target_y % 10;
//        current_node.f = current_node.h + current_node.g;
//        for (i = 0; i < walls.size(); i++) {
//            if (walls[i].x == current_node.x && walls[i].y == current_node.y) {
//                return -1;
//            }
//        }
//        open.push_back(current_node);
//        while (!open.empty()) {
//            int flg, flg2;
//            //寻找open节点里f最小的节点
//            min_f = open[0].f;
//            min_index = 0;
//            for (i = 0; i < open.size(); i++) {
//                if (open[i].f < min_f) {
//                    min_f = open[i].f;
//                    min_index = i;
//                }
//            }
//            current_node = open[min_index];
//            //去除Open里的当前节点，在closed里添加
//            open.erase(open.begin() + min_index);
//            closed.push_back(current_node);
//            //判断目标点是否在Open里
//            if (current_node.x == target_x && current_node.y == target_y)
//                return current_node.g;
//            //检验四周的节点
//            for (j = 0; j < 8; j++) {
//                flg = 1;
//                flg2 = 1;
//                next_node.x = (current_node.x % 10 + 10 + step[j][0]) % 10 + (current_node.x / 10 + 10 + step[j][1]) % 10 * 10;
//                next_node.y = (current_node.y % 10 + 10 + step[j][2]) % 10 + (current_node.y / 10 + 10 + step[j][3]) % 10 * 10;
//                next_node.g = current_node.g + 1;
//                next_node.h = int(abs(next_node.x / 10 - target_x / 10) + abs(next_node.x % 10 - target_x % 10) + abs(next_node.y / 10 - target_y / 10) + abs(next_node.y % 10 - target_y % 10));
//                next_node.f = next_node.g + next_node.h;
//                for (i = 0; i < walls.size(); i++) {
//                    if (walls[i].x == next_node.x && walls[i].y == next_node.y) {
//                        flg = 0;
////                       cout << "2" << endl;
//                        break;
//                    }
//                    //cout << walls.size() << endl;
//                }
//                if (flg) {
//                    for (i = 0; i < closed.size(); i++) {
//                        if (closed[i].x == next_node.x && closed[i].y == next_node.y) {
//                            flg = 0;
////                           cout << "3" << endl;
//                            break;
//                        }
//                    }
//                }
//                else
//                    continue;
//                if (flg) {
//                    for (i = 0; i < open.size(); i++) {
//                        if (open[i].x == next_node.x && open[i].y == next_node.y) {
//                            if (open[i].f > next_node.f) {
//                                open[i].g = next_node.g;
//                                open[i].f = next_node.f;
//                            }
//                            flg2 = 0;
//                            break;
//                        }
//                    }
//                }
//                else
//                    continue;
//
//                if (flg2)
//                    open.push_back(next_node);
//            }
////            cout << "1" << endl;
//        }
//        if (open.empty())
//            return -1;
//    }
//};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string> s(deadends.begin(), deadends.end());
        if(s.count(start))
            return -1;
        if(start == target)
            return 0;
        int res = 0;
        queue<string> q;
        q.push(start);
        while(!q.empty()) {
            int n = q.size();
            res++;
            for(int i = 0; i < n; i++) {
                string x = q.front();
                q.pop();
                string tmp;
                for(int j = 0; j < x.length(); j++) {
                    tmp = x;
                    int y = tmp[j] - '0';
                    tmp[j] = '0' + (y+1)%10;
                    if(tmp == target)
                        return res;
                    if(!s.count(tmp)){
                        s.insert(tmp);
                        q.push(tmp);
                    }

                    tmp = x;
                    tmp[j] = '0' + (y+9)%10;
                    if(tmp == target)
                        return res;
                    if(!s.count(tmp)){
                        s.insert(tmp);
                        q.push(tmp);
                    }
                }
            }
        }
        return -1;
    }

};


//int main(int args, char** argv){
//    string target = "0202";
//    vector<string> dead;
//    dead.push_back("0201");
//    dead.push_back("0101");
//    dead.push_back("0102");
//    dead.push_back("1212");
//    dead.push_back("2002");
//    cout << openLock(dead,target);
//}