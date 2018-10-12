//
// Created by chenzhiji on 18-10-11.
//
#include "iostream"
#include "math.h"
#include "queue"

using namespace std;

class NumSquares {
public:
    int numSquares(int n) {
        int num=1;
        queue<int> s;
        s.push(n);
        while(!s.empty()){
            int size, min, next;
            size = s.size();
            for(int i=0; i < size;i++){
                min = int(sqrt(s.front()));
                for(int j=1; j <= min; j++){
                    next = s.front() - j * j;
                    if(next == 0) {
                        cout << num << endl;
                        return num;
                    }
                    else
                        s.push(next);
                }
                s.pop();
            }
            num++;
        }
    }
};

int main(){
//    Solution* s = new Solution();
//需手动释放内存delete s
    NumSquares s;
//    Solution s = Solution();
    s.numSquares(12);

}