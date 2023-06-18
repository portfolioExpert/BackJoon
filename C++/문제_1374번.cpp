#include <iostream>
#include <algorithm>
using namespace std;

//문제 1374번 강의실 -> 우선순위 큐
#include <queue>
#include <vector>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>>v;
    priority_queue<int, vector<int>, greater<int>>pq;//강의실 수
    for(int i = 0;i<n;i++){
        int num, from, to;
        cin >> num >> from >> to;
        v.push_back({from, to});
    }
    sort(v.begin(), v.end());
    int result = 0;

    for(int i = 0;i<v.size();){
        if(pq.empty()){
            pq.push(v[i].second);
            i++;
        }
        else{
            if(pq.top() >= v[i].first){
                //시작시간과 종료시간이 같다면 빼주고 처리 해야하므로
                if(pq.top() == v[i].first)
                    pq.pop();
                pq.push(v[i].second);
                i++;
            }
            else{
                result = max(result, (int)pq.size());
                pq.pop();
            }
        }
    }
    result = max(result, (int)pq.size());
    cout << result;
}