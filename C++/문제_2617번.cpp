//문제 2617번 구슬 찾기 -> DFS
#include <vector>
#include <cstring>
vector<int>v[101];
bool visit[101];
int compare[101][101];
int n, m;
void dfs(int go, int start){
    for(int i = 0;i<v[go].size();i++){
        if(visit[v[go][i]] == 0){
            visit[v[go][i]] = 1;
            compare[v[go][i]][start] = 1;
            compare[start][v[go][i]] = -1;
            compare[v[go][i]][go] = 1;
            compare[go][v[go][i]] = -1;
            dfs(v[go][i], start);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    int result = 0;
    for(int i = 0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        compare[num1][num2] = 1;
        compare[num2][num1] = -1;
        v[num2].push_back(num1);
    }
    for(int i = 1;i<=n;i++){
        memset(visit, 0, sizeof(visit));
        visit[i] = 1;
        dfs(i, i);
    }
    for(int i = 1;i<=n;i++){
        int right = 0;
        int left = 0;
        for(int j = 1;j<=n;j++){
            if(compare[i][j] == 1)
                right++;
            else if(compare[i][j] == -1)
                left++;
        }
        if(right > (n / 2) || left > (n / 2))
            result++;
    }
    cout << result;
}