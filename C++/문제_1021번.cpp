#include <iostream>
#include <algorithm>
using namespace std;

//문제 1021번 회전하는 큐 -> 덱
#include <deque>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    deque<int>dq;
    int result = 0;
    for(int i = 1;i<=n;i++){
        dq.push_back(i);
    }
    for(int i = 0;i<m;i++){
        int num;
        cin >> num;
        //왼쪽으로 쭉 빼보기
        int left = 0;
        deque<int>leftq = dq;
        while(!leftq.empty() && leftq.front() != num){
            left++;
            leftq.push_back(leftq.front());
            leftq.pop_front();
        }
        leftq.pop_front();

        //오른쪽으로 쭉 빼보기
        int right = 0;
        deque<int>rightq = dq;
        while(!rightq.empty() && rightq.front() != num){
            right++;
            rightq.push_front(rightq.back());
            rightq.pop_back();
        }
        rightq.pop_front();
        if(left > right){
            while(!dq.empty()){
                dq.pop_front();
            }
            while(!rightq.empty()){
                dq.push_back(rightq.front());
                rightq.pop_front();
            }
            result+= right;
        }
        else{
            while(!dq.empty()){
                dq.pop_front();
            }
            while(!leftq.empty()){
                dq.push_back(leftq.front());
                leftq.pop_front();
            }
            result+= left;
        }
    }
    cout << result;
}