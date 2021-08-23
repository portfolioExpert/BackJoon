//문제 2637번 장난감조립 -> 위상정렬 응용
#include <queue>
#include <vector>
vector<pair<int,int>>v[101];
int total[101];//
int visit[101][101];
queue<int>q;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int x, y, k;
        cin >> x >> y >> k;
        v[y].push_back({x,k});
        total[x]++;
    }
    vector<int>ans;
    for(int i = 1;i<=n;i++){
        if(v[i].size() == 0){
            ans.push_back(i);
        }
        if(total[i] == 0){
            q.push(i);
            //곱을 위한 1
            visit[i][i] = 1;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0;i<v[cur].size();i++){
            //다음 노드에 가중치를 전부 곱해서 넘겨준다, 각각 필요한 기본재료를 넣어주는 작업
            for(int j = 1;j<=n;j++){

                visit[v[cur][i].first][j] += visit[cur][j] * v[cur][i].second;
            }
            //다음으로 넘어갈 수 있도록 빼주고
            total[v[cur][i].first]--;
            //갯수가 0이면 큐에 넣어줌
            if(total[v[cur][i].first] == 0)
                q.push(v[cur][i].first);
        }
    }
    //n번째에서 기본재료로 만들 수 있는 것을 출력
    for(int i = 1;i<=n;i++){
        if(visit[n][i])
            cout << i << " " << visit[n][i] <<"\n";
    }
}