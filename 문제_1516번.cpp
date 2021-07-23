//문제 1516번 게임 개발 -> 위상정렬
#include<vector>
#include<queue>
queue<int>q;
vector<int>v[501];
int dp[501];
int visit[501];
int cost[501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> cost[i];
        dp[i] = cost[i];
        while(1){
            int num;
            cin >> num;
            if(num == -1)
                break;
            v[num].push_back(i);
            //여기서 많이 틀렸다
            visit[i]++;
        }
        //이부분도 주의
        if(visit[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int go = q.front();
        q.pop();
        for(int y : v[go]){
            dp[y] = max(dp[y], dp[go] + cost[y]);
            visit[y]--;
            if(visit[y] == 0)
                q.push(y);
        }
    }
    for(int i = 1;i<=n;i++){
        cout << dp[i] << "\n";
    }
}