//
// Created by weekchen on 18-10-14.
//

#include "iostream"
#include "vector"
#include "stack"
#include "cmath"

using namespace std;

class EvalRPN {
public:
    int evalRPN(vector<string>& tokens) {
        stack<double> s;
        double result;
        for(int i=0;i < tokens.size(); i++){
            int length = int(tokens[i].size());
            if(tokens[i][length - 1] - '0' >= 0  && tokens[i][length - 1] - '0' <= 9){
                double num = 0;
                if(tokens[i][0] != '-')
                    for(int j = 0; j <= length - 1; j++)
                        num += (tokens[i][j] - '0') * pow(10, length-1-j);
                else{
                    for(int j = 1; j <= length - 1; j++)
                        num += (tokens[i][j] - '0') * pow(10, length-1-j);
                    num = -1 * num;
                }
                s.push(num);
            }
            else{
                int num1, num2;
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                switch(tokens[i][0]){
                    case '/' :
                        result = num2 / num1;
                        break;
                    case '*' :
                        result = num2 * num1;
                        break;
                    case '+' :
                        result = num2 + num1;
                        break;
                    case '-':
                        result = num2 - num1;
                        break;
                }
                s.push(result);
            }
        }
        return s.top();
    }
};

int main(){
    EvalRPN* s = new EvalRPN();
    vector<string>  r = {"2","1","+","3","*"};
    cout << s->evalRPN(r) << endl;
    return 0;
}
