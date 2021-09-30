//문제 12784번 -> DFS
//실패 이유: 리프노드 정의를 잘못했다
//반례
//1
//2 1
//1 2 1
//답: 1 오답: 987654321
#include <vector>
#include <cstring>
bool visit[1001];
int cost[1001][1001];
vector<int>v[1001];
int t, n, m, result;
int topdown(int go){
    //leaf node
    //단순하게 사이즈가 1이면 안되고 그곳을 방문한 곳이여야 리프노드
    if(v[go].size() == 1 && visit[v[go][0]] == 1){
        return 987654321;
    }
    int ret = 0;
    for(int i = 0;i<v[go].size();i++){
        if(visit[v[go][i]] == 0){
            visit[v[go][i]] = 1;
            ret+=min(cost[go][v[go][i]], topdown(v[go][i]));
        }
    }
    return ret;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0;i<t;i++){
        cin >> n >> m;
        memset(visit, 0 ,sizeof(visit));
        memset(cost, 0, sizeof(cost));
        for(int j = 0;j<m;j++){
            int num1, num2, weight;
            cin >> num1 >> num2 >> weight;
            v[num1].push_back(num2);
            v[num2].push_back(num1);
            cost[num1][num2] = weight;
            cost[num2][num1] = weight;
        }
        memset(visit, 0, sizeof(visit));
        visit[1] = 1;
        cout << topdown(1) << "\n";
        for(int j = 0;j<=1000;j++){
            v[j].clear();
        }
    }
}