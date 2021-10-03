//문제 2056번 작업 -> 위상정렬 문제
#include <vector>
#include <queue>
int visit[10001];
int cost[10001];
vector<int>v[10001];
queue<int>q;
int dp[10001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> cost[i];
        dp[i] = cost[i];
        int num;
        cin >> num;
        for(int j = 0;j<num;j++){
            int node;
            cin >> node;
            v[node].push_back(i);
            //처리해야할 횟수를 저장해주고
            visit[i]++;
        }
    }
    //처리해야할 횟수가 0인 것을 넣어주고
    for(int i = 1;i<=n;i++){
        if(visit[i] == 0){
            q.push(i);
        }
    }
    int result = 0;
    //빼주면서 횟수가0인 것을 넣어주고
    //전의 값중에서 최대를 dp로 저장해야한다
    while(!q.empty()){
        int go = q.front();
        q.pop();
        for(int y : v[go]){
            dp[y] = max(dp[y], dp[go] + cost[y]);
            visit[y]--;
            if(visit[y] == 0){
                q.push(y);
            }
        }
    }
    //이것을 해줘야한다 while안에 넣으면 차이가 존재
    for(int i = 1;i<=n;i++){
        result = max(result, dp[i]);
    }
    cout << result;
    return 0;
}