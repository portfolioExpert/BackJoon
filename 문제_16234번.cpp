#include <iostream>
#include <algorithm>
using namespace std;

//문제 16234번
#include <queue>
#include <cstring>
#include <vector>
queue <pair<int,int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1 ,-1};
int map[51][51], after[51][51];
int visit[51][51];
bool flag;
int result, n, l, r;
void bfs(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i ,j;
    cin >> n >> l >> r;
    for(i = 0;i<n;i++){
        for(j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    while(1){
        flag = 0;
        memset(visit, 0 ,sizeof(visit));
        for(i = 0;i<n;i++){
            for(j = 0;j<n;j++){
                if(after[i][j] == 0)
                    bfs(i, j);
            }
        }
        if(flag == 0)//안움직였을경우
            break;
        result++;
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                map[i][j] = after[i][j];
                after[i][j] = 0;
            }
        }
    }
    cout << result;
}
void bfs(int x, int y){
    vector<pair<int,int>>v;
    memset(visit, 0, sizeof(visit));
    int sum = map[x][y];
    visit[x][y] = 1;
    int cnt = 1;
    q.push({x, y});
    v.push_back({x, y});
    while(!q.empty()){
        int gx = q.front().first;
        int gy = q.front().second;
        q.pop();
        for(int i =0;i<4;i++){
            int gox = gx + dx[i];
            int goy = gy + dy[i];
            if(gox>=0 && gox < n && goy>=0 && goy < n && visit[gox][goy] == 0 && abs(map[gx][gy] - map[gox][goy]) >= l && abs(map[gx][gy] - map[gox][goy]) <= r){
                visit[gox][goy] = 1;
                q.push({gox, goy});
                sum+=map[gox][goy];
                cnt++;
                v.push_back({gox, goy});
            }
        }
    }
    if(sum != map[x][y])
        flag = 1;
    sum/=cnt;
    for(int i = 0;i<v.size();i++){
        after[v[i].first][v[i].second] = sum;
    }
}