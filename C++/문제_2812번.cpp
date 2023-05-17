#include <iostream>
#include <algorithm>
using namespace std;

//문제 2812번 크게 만들기 -> 스택, 그리디
//스택 버전
#include <stack>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    stack<char>s;
    int n, k;
    cin >> n >> k;
    string str, result = "";
    cin >> str;
    int len = n - k;
    for(int i = 0;i<str.size();i++){
        if(s.empty())
            s.push(str[i]);
        else{
            //뺄 때 스텍에 넣은것 + 현재 남은 숫자의 개수 > 내가 구하는 길이보다
            while(!s.empty() && s.top() < str[i] && s.size() + n - i > len){
                s.pop();
            }
            //구해야하는 길이가 부족하다면 넣어준다.
            if(s.size() < len)
                s.push(str[i]);
        }
    }
    while(!s.empty()){
        result+=s.top();
        s.pop();
    }
    reverse(result.begin(), result.end());
    cout << result;
}