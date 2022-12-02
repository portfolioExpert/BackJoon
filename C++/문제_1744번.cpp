#include <iostream>
#include <algorithm>
using namespace std;

//문제 1744번 수 묶기 -> 그리디, 우선순위 큐
//로직을 0을 기준으로
//각 큐가 1개씩 남으면 걍 더하면 되고
//1개 0개, 0개 1개도 걍 더하면 된다
#include <queue>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    priority_queue<int>plus;//크게 가야됨
    priority_queue<int>minus;//이것도 -를 붙여서 크게 만들어야된다
    cin >> n;
    int result = 0;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        if(num > 0){
            plus.push(num);
        }
        else{
            minus.push(-num);
        }
    }
    while(plus.size() > 1){
        int first = plus.top();
        plus.pop();
        int second = plus.top();
        plus.pop();
        result += max(first * second, first + second);
    }
    while(minus.size() > 1){
        int first = minus.top();
        minus.pop();
        int second = minus.top();
        minus.pop();
        result += max(first * second,-first + -second);
    }
    if(!plus.empty()){
        result+=plus.top();
    }
    if(!minus.empty())
        result+=-minus.top();
    cout << result;
}