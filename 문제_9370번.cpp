//문제 9370번 미확인 도착지 -> 다익스트라 응용
#include <vector>
#include <queue>
int dp[2001];
priority_queue<pair<int,int>>pq;//가중치, 노드
void dijkstra(int go, vector<pair<int,int>>v[]){
    dp[go] = 0;
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int i = 0;i<v[now].size();i++){
            int next = v[now][i].first;
            int val = v[now][i].second + cost;
            if(dp[next] > val){
                pq.push({-val,next});
                dp[next] =val;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        vector<pair<int,int>>v[2001];
        vector<int>target;
        int n, m, t;
        cin >> n >> m >> t;
        fill_n(dp, n+1, 214748364);
        int s ,g ,h;
        cin >> s >> g >> h;
        for(int j = 0;j<m;j++){
            int a, b, d;
            cin >> a >> b >> d;
            d *= 2;
            //해당 길만 홀수로 만들어주어 지나갈때 더해주면 값이 홀수가 된다
            if(a == g && b == h){
                d+=1;
            }
            else if(b == g && a == h){
                d+=1;
            }
            v[a].push_back({b,d});
            v[b].push_back({a,d});
        }
        for(int j = 0;j<t;j++){
            int num;
            cin >> num;
            target.push_back(num);
        }
        sort(target.begin(), target.end());
        pq.push({0, s});
        dijkstra(s, v);
        for(int y : target){
            //다만 여기서 max값을 짝수로 해줘야 한다
            if(dp[y] % 2 == 1)
                cout << y << " ";
        }
        cout << "\n";
    }
}