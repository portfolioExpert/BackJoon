#include <iostream>
#include <algorithm>
using namespace std;

//문제 6198번 옥상 정원 꾸미기 -> 스택
//i 번째 빌딩의 키가 h이고, 일렬에 오른쪽을 보고 있다.
#include <stack>
stack<int>s;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    long long result = 0;
    int arr[80001];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i<n;i++){
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
            result+=s.size();
        }
        s.push(arr[i]);
    }
    //나머지 처리
    while(!s.empty()){
        s.pop();
        result+=s.size();
    }
    cout << result;
}