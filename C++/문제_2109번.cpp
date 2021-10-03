//문제 2109번 순회강연 > 우선순위 큐
#include <queue>
#include <vector>
vector<pair<int,int>>v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 0;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int p, d;
        cin >> p >> d;
        v.push_back({d, -p});
    }
    //날짜 빠른 것, 가격 높은 순 정렬
    sort(v.begin(), v.end());
    priority_queue<int>pq;
    //n일 동안 진행 가능
    for(int i = 0;i<n;i++){
        //앞에 있는 것이 가장 크므로 일단 넣고
        result+=-v[i].second;
        pq.push(v[i].second);
        //큐 사이즈 보다 day가 낮으면 작은 것을 빼준다
        if(pq.size() > v[i].first){
            result+=pq.top();
            pq.pop();
        }
    }
    cout << result;
}