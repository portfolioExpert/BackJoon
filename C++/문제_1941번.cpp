//문제 1941번 소문난 칠공주 -> 백트래킹, BFS
#include <string>
#include <cstring>
#include <vector>
#include <queue>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visit[26];
char map[26][26];
bool visited[26][26];
int result;
//연결점 체크
void checkbfs(int x, int y){
    vector<char>v;
    queue<pair<int,int>>q;
    q.push({x, y});
    v.push_back(map[x][y]);
    int cnt = 1;
    while(!q.empty()){
        int gx = q.front().first;
        int gy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gox = gx + dx[i];
            int goy = gy + dy[i];
            if(gox >= 0 && gox < 5 && goy >= 0 && goy < 5 && visited[gox][goy] == 0 && visit[gox * 5 + goy % 5] == 1){
                v.push_back(map[gox][goy]);
                visited[gox][goy] = 1;
                q.push({gox,goy});
                cnt++;
            }
        }
    }
    if(cnt == 7){
        int count = 0;
        for(char y : v){
            if(y == 'S')
                count++;
        }
        if(count >= 4)
            result++;
    }
}
//백트래킹으로 경우의 수 체크
void dfs(int index, int cnt){
    if(index > 25)
        return;
    if(cnt == 7){
        memset(visited, 0, sizeof(visited));
        visited[(index-1) / 5][(index - 1) % 5] = 1;
        checkbfs((index - 1)/5, (index - 1) % 5);
        return;
    }
    for(int i = index;i<25;i++){
        visit[i] = 1;
        dfs(i+1, cnt + 1);
        visit[i] = 0;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<19;i++){
        visit[i] = 1;
        dfs(i+1, 1);
        visit[i] = 0;
    }
    cout << result;
}