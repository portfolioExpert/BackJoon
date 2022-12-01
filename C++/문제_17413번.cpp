#include <iostream>
#include <algorithm>
using namespace std;

//문제 17413번 단어 뒤집기 2 -> 스택, 큐, 자료구조
#include <stack>
#include <queue>
#include <vector>
int main(){
    string str;
    stack<char>s;//일반 단어 스택
    stack<char>div;//꺽세를 넣는 스택
    queue<char>q;//꺽세일 경우는 큐에 넣어야된다
    getline(cin, str);
    for(int i = 0;i<str.size();i++){
        //꺽세가 없을 경우
        if(div.empty() && str[i] != '<' && str[i] != '>' && str[i] != ' '){
            s.push(str[i]);
            continue;
        }
        //꺽세가 들어있을 경우 무조건 큐에 넣어준다
        if(!div.empty() && str[i] != '<' && str[i] != '>'){
            q.push(str[i]);
            continue;
        }
        if(str[i] == '<'){
            div.push('<');
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
        }
        //꺽세로 닫혀있을경우
        if(str[i] == '>'){
            cout << "<";
            while(!q.empty()){
                cout << q.front();
                q.pop();
            }
            cout << ">";
            div.pop();
        }
        //꺽세가 없고 공백일경우
        if(div.empty() && str[i] == ' '){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            cout << " ";
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}