//문제 16197번 두 동전 -> 백트래킹
//20 * 20을 완탐하느라 성능은 최악
#include <vector>
#include <queue>
int n, m;
char map[21][21];
bool visit[21][21];
int dx[4] = {1, -1 ,0 ,0};
int dy[4] = {0 ,0 ,1, -1};
int result = 987654321;
void dfs(vector<pair<int,int>>v, int cnt){
    //10번 누른 것이 넘었을때
    if(cnt > 10){
        return;
    }
    //이미 둘다 나갔을 때
    if((v[0].first < 0 || v[0].first >= n ||v[0].second >= m || v[0].second < 0) && (v[1].first < 0 || v[1].first >= n || v[1].second < 0 || v[1].second >= m))
        return;
    //하나만 나간 것 판정
    if(v[0].first >= 0 && v[0].first < n && v[0].second >= 0 && v[0].second < m && (v[1].first >= n || v[1].first < 0 || v[1].second >= m || v[1].second < 0)){
        result = min(result, cnt);
        return;
    }
    if(v[1].first >= 0 && v[1].first < n && v[1].second >= 0 && v[1].second < m && (v[0].first >= n || v[0].first < 0 || v[0].second >= m || v[0].second < 0)){
        result = min(result, cnt);
        return;
    }
    vector<pair<int,int>>have;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<2;j++){
            int gox = v[j].first + dx[i];
            int goy = v[j].second + dy[i];
            if(gox >= 0 && gox < n && goy >= 0 && goy < m && map[gox][goy] == '#'){
                have.push_back({v[j].first, v[j].second});
                continue;
            }
            have.push_back({gox, goy});
        }
        for(int j = 0;j<2;j++){
            int gox = have[j].first;
            int goy = have[j].second;
            visit[gox][goy] = 1;
        }
        dfs(have, cnt + 1);
        for(int j = 0;j<2;j++){
            int gox = have[j].first;
            int goy = have[j].second;
            visit[gox][goy] = 0;
        }
        have.clear();
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    vector<pair<int,int>>coin;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 'o')
                coin.push_back({i, j});
        }
    }
    dfs(coin, 0);
    if(result == 987654321)
        cout << -1;
    else
        cout << result;
}