#include <iostream>
#include <algorithm>
using namespace std;

//문제 2075번 N번째 큰 수 -> 우선순위 큐
#include <queue>
priority_queue<int>pq;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int num;
            cin >> num;
            pq.push(-num);
            if(pq.size() > n){
                pq.pop();
            }
        }
    }
    cout << -pq.top();
}
