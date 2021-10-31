//문제 18405번
#include <queue>
int map[201][201];
vector<pair<int,pair<int,int>>>v;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, k, s, x, y;
void bfs(int time){
    while(time--){
        vector<pair<int,pair<int,int>>>newv;
        for(int i = 0;i<(int)v.size();i++){
            int number = v[i].first;
            int gox = v[i].second.first;
            int goy = v[i].second.second;
            for(int j = 0;j<4;j++){
                int gx = gox + dx[j];
                int gy = goy + dy[j];
                if(gx >= 1 && gx <= n && gy >= 1 && gy <= n && map[gx][gy] == 0){
                    map[gx][gy] = number;
                    newv.push_back({map[gx][gy], {gx, gy}});
                }
            }
        }
        v = newv;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> map[i][j];
            if(map[i][j] != 0)
                v.push_back({map[i][j], {i,j}});
        }
    }
    sort(v.begin(), v.end());
    cin >> s >> x >> y;
    bfs(s);
    cout << map[x][y];
}