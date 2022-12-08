#include <iostream>
#include <algorithm>
using namespace std;

//문제 16637번 괄호 추가하기 -> 백트래킹, 브루트 포스
#include <string>
int n;
int result = 0;
string str;
int cal(int a, int b, char ch){
    if(ch == '+'){
        return a + b;
    }
    else if(ch == '-')
        return a - b;
    else
        return a * b;
}

void dfs(int index, int value){
    if(index >= n){
        //계산해야한다.
        result = max(result, value);
        return;
    }

    char ch = '+';

    if(index >= 1)
        ch = str[index - 1];

    //현재 숫자랑 지금까지 더한 값을 계산해서 넘기기
    int number = cal(value, str[index] - '0', ch);
    //1. 괄호 넘기기
    dfs(index + 2, number);

    //2. 괄호 쳐서 넘기기
    if(index + 2 < n){
        //현재 값과 다음 값을 계산하고
        number = cal(str[index] - '0', str[index + 2] - '0', str[index + 1]);
        //지금까지 계산한 값과 괄호친 부분을 계산해서 넣고 넘겨준다.
        number = cal(value, number, ch);
        dfs(index + 4, number);
    }
}
int main(){
    cin >> n;
    cin >> str;
    dfs(0, 0);
    cout << result;
}