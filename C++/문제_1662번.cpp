//문제 1662번 압축 -> 스택
#include <stack>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    stack<char>s;
    stack<int>mul;
    string str;
    cin >> str;
    int result = 0;
    for(int i = 0;i<str.size();i++){
            if(str[i] >= '0' && str[i] <= '9'){
                s.push(str[i]);
            }
            if(str[i] == '('){
                s.push(str[i]);
                mul.push(-1);
            }
            if(str[i] == ')'){
                //길이 측정
                int len = 0;
                while(!s.empty() && s.top() != '('){
                    len++;
                    s.pop();
                }
                s.pop();//(빼주기
                int number = s.top() - 48;//앞 숫자
                s.pop();//앞 숫자 빼주기
                while(!mul.empty() && mul.top() != -1){
                    len+=mul.top();
                    mul.pop();
                }
                mul.pop(); // -1 빼주기
                mul.push(len * number);
            }
        }
    while(!mul.empty()){
        result += mul.top();
        mul.pop();
    }
    cout << s.size() + result;
}