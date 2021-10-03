#include <iostream>
#include <algorithm>
using namespace std;

//문제 4485번
#include <queue>
#include <cstring>
int dx[4] = {1, -1 ,0, 0};
int dy[4] = {0, 0, 1, -1};
queue <pair<int ,int>> q;
int map[126][126];
int visit[126][126];
int n;
void dijkstra();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i ,j, cnt = 1;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0;i<n;i++){
            fill_n(visit[i], n, 987654321);
        }
        for(i = 0;i<n;i++){
            for(j = 0;j<n;j++){
                cin >> map[i][j];
            }
        }
        dijkstra();
        cout <<"Problem " << cnt << ": " << visit[n-1][n-1] << "\n";
        cnt++;
    }
}
void dijkstra(){
    q.push({0, 0});
    visit[0][0] = map[0][0];
    while(!q.empty()){
        int gx = q.front().first;
        int gy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gox = gx + dx[i];
            int goy = gy + dy[i];
            if(gox >=0 && gox < n && goy >=0 && goy < n){
                if(visit[gox][goy] <= visit[gx][gy] + map[gox][goy])
                    continue;
                visit[gox][goy] = visit[gx][gy] + map[gox][goy];
                q.push({gox,goy});
            }
        }
    }
}