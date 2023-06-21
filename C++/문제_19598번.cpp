#include <iostream>
#include <algorithm>
using namespace std;

//문제 19598번 최소 회의실 개수 -> 우선순위 큐, 그리디, 정렬
#include <vector>
#include <queue>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int>>pq;//끝나는 시간을 담되 minheap을 유지
    vector<pair<int,int>>v;
    int n, result = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int from, to;
        cin >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<v.size();i++){
        pq.push(v[i].second);
        while(!pq.empty() && v[i].first >= pq.top()){
            pq.pop();
        }
        result = max(result, (int)pq.size());
    }
    cout << result;
}