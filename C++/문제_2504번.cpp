//문제 2504번 괄호의 값 -> 스택
#include <string>
#include <stack>
int main(){
    int result = 0;
    stack<int>s;
    stack<int>number;
    string str;
    cin >> str;
    for(int i = 0;i<(int)str.size();i++){
        if(str[i] == '('){
            s.push(-1);
        }
        else if(str[i] == '['){
            s.push(-2);
        }
        else{
            if(s.empty()){
                cout << 0;
                return 0;
            }
            if(!s.empty() && str[i] == ')'){
                if(s.top() == -1){
                    s.pop();
                    s.push(2);
                }
                else{
                    int sum = 0;
                    while(!s.empty() > 0 && s.top() != -1){
                        if(s.top() == -2){
                            cout << 0;
                            return 0;
                        }
                        sum+=s.top();
                        s.pop();
                    }
                    if(s.empty()){
                        cout << 0;
                        return 0;
                    }
                    s.pop();
                    s.push(sum * 2);
                }
            }
            else if(!s.empty() && str[i] == ']'){
                if(s.top() == -2){
                    s.pop();
                    s.push(3);
                }
                else{
                    int sum = 0;
                    while(!s.empty() && s.top() != -2){
                        if(s.top() == -1){
                            cout << 0;
                            return 0;
                        }
                        sum+=s.top();
                        s.pop();
                    }
                    if(s.empty()){
                        cout << 0;
                        return 0;
                    }
                    s.pop();
                    s.push(sum * 3);
                }
            }
            else{
                cout << 0;
                return 0;
            }
        }
    }
    while(!s.empty()){
        if(s.top() == -1 || s.top() == -2){
            cout << 0;
            return 0;
        }
        result+=s.top();
        s.pop();
    }
    cout << result;
    return 0;
}
//반례
//([()(())](())([[]]()))()[()]