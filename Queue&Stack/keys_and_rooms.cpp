//
// Created by chenzhiji on 18-10-22.
//
#include "iostream"
#include "vector"
#include "queue"

using namespace std;

class KeysAndRooms {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> keys;
        for(auto i : rooms[0])
            keys.push(i);
        visited[0] = true;
        while(!keys.empty()){
            int cur = keys.front();
            visited[cur] = true;
            keys.pop();
            for(auto i : rooms[cur])
                if(!visited[i])
                    keys.push(i);
        }
        for(auto i : visited){
            if(i == false)
                return false;
        }
        return true;
    }
};

int main(){
    KeysAndRooms s;
    vector<vector<int>> rooms{{1,3},{3,0,1},{2},{0}};
    s.canVisitAllRooms(rooms);
}