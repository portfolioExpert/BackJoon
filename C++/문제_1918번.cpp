//문제 1918번 후위수식
#include <string>
#include <stack>
stack <char> s;
int main(){
    string str;
    cin >> str;
    for(int i = 0;i<str.size();i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            cout << str[i];
        else if(str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(str[i] == '+' || str[i] == '-'){
            if(!s.empty()){
                while(!s.empty() && s.top()!= '('){
                    cout << s.top();
                    s.pop();
                }
            }
            s.push(str[i]);
        }
        else if(str[i] == '*' || str[i] == '/'){
            if(!s.empty()){
                while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                    cout << s.top();
                    s.pop();
                }
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}