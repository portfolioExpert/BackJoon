//문제 1689번 겹치는 선분 -> 그리디
#include <vector>
#include <queue>
priority_queue<int>pq;
vector<pair<int,int>>v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 1;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int from, to;
        cin >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());
    pq.push(-v[0].second);
    for(int i = 1;i<(int)v.size();i++){
        while(pq.size() > 0 && -pq.top()<=v[i].first)
            pq.pop();
        pq.push(-v[i].second);
        result = max(result, (int)pq.size());
    }
    cout << result;
}