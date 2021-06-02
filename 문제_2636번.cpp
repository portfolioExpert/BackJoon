//문제 2636번
#include <queue>
#include <vector>
vector<pair<int ,int>>v;
queue <pair<int ,int>> q;
queue<pair<int,int>>ch;
int map[101][101];
int visit[101][101];
int n, m, result, val;
void check();
void bfs();
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0 ,0 ,1 ,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    map[0][0] = -1;
    ch.push({0, 0});
    check();
    while(1){
        bool flag = 0;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(map[i][j] == 1){
                    flag = 1;
                    cnt++;
                }
            }
        }
        if(flag == 0)
            break;
        result++;
        val = cnt;
        bfs();
        check();
    }
    cout << result << "\n" << val;
}
void check(){
    while(!ch.empty()){
        int gox = ch.front().first;
        int goy = ch.front().second;
        ch.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy < m){
                if(map[gx][gy] == 0){
                    ch.push({gx, gy});
                    map[gx][gy] = -1;
                }
                if(map[gx][gy] == 1 && visit[gx][gy] == 0){
                    q.push({gx, gy});
                    visit[gx][gy] = 1;
                }
            }
        }
    }
}
void bfs(){
    queue<pair<int,int>> in;
    while(!q.empty()){
        int gx = q.front().first;
        int gy = q.front().second;
        q.pop();
        in.push({gx, gy});
    }
    while(!in.empty()){
        int gox = in.front().first;
        int goy = in.front().second;
        in.pop();
        map[gox][goy] = -1;
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy < m){
                //내부 공기 처리
                if(map[gx][gy] == 0){
                    ch.push({gx, gy});
                    map[gx][gy] = -1;
                }
                if(visit[gx][gy] == 0 && map[gx][gy] == 1){
                    q.push({gx, gy});
                    visit[gx][gy] = 1;
                }
            }
        }
    }
}