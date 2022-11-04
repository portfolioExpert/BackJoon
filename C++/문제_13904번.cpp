//문제 13904번 과제 -> 우선순위 큐
#include <queue>
#include <vector>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    priority_queue<int>pq;//정답만 넣을 것
    int n;
    cin >> n;
    vector<pair<int,int>>v;
    for(int i = 0;i<n;i++){
        int d, w;
        cin >> d >> w;
        v.push_back({d, w});
    }
    sort(v.begin(), v.end());
    int time = 1;
    int result = 0;
    int index = 0;
    while(index < v.size()){
        while(time == v[index].first){
            pq.push(-v[index].second);
            index++;
        }
        //시간에 비해 큐가 많으면 적은 점수순으로빼준다.
        while(pq.size() > time){
            pq.pop();
        }
        time++;
    }
    while(!pq.empty()){
        result+=-pq.top();
        pq.pop();
    }
    cout << result;
}