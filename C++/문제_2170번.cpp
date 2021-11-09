//문제 2170번 선긋기 -> 라인 스위핑
#include <vector>
#include <queue>
priority_queue<int>pq;
vector<pair<int,int>>v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 0;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int from, to;
        cin >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());
    int left = v[0].first, right = v[0].second;
    for(int i = 1;i<n;i++){
        if(v[i].first >= left && v[i].first <= right){
            right = max(right, v[i].second);
        }
        else{
            result += right - left;
            left = v[i].first;
            right = v[i].second;
        }
    }
    if(n == 1)
        cout << v[0].second - v[0].first;
    else
        cout << result + (right - left);
}