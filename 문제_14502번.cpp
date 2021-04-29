#include <iostream>
#include <algorithm>
using namespace std;

//문제 14502번
#include <queue>
#include <vector>
vector <pair<int, int>> q;
queue <pair<int, int>> poq;
int map[9][9], copy[9][9];
int result, n, m;
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
void bfs();
void makewall(int x, int y, int count);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 2){//벡터에 원래 바이러스 위치 저장
                q.push_back({i, j});
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j] == 0){//벽세우고 bfs진행
                map[i][j] = 1;
                makewall(i,j , 1);
                map[i][j] = 0;
            }
        }
    }
    cout << result;
    return 0;
}
void bfs(){
    queue<pair<int ,int>> inq;//원래 바이러스 좌표를 q에 넣기
    for(int i = 0; i<q.size();i++){
        inq.push(q[i]);
    }
    while(!inq.empty()){
        int gox = inq.front().first;
        int goy = inq.front().second;
        inq.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx>=0 && gx < n && gy>=0 && gy < m && map[gx][gy] == 0){
                inq.push({gx, gy});
                poq.push({gx, gy});
                map[gx][gy] = 2;
            }
        }
    }
    //안전지대 갯수 체크
    int sum = 0;
    for(int i = 0; i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 0)
                sum++;
        }
    }
    result = max(result, sum);
}

void makewall(int x, int y, int count){
    if(count == 3){//벽 3개를 세웠을 경우 bfs진행
        bfs();
        while(!poq.empty()){//바꿨던 좌표들 전부 초기화
            int f = poq.front().first;
            int s = poq.front().second;
            map[f][s] = 0;
            poq.pop();
        }
        return;
    }
    for(int i = 0; i< n;i++){//재귀로 벽세우기
        for(int j=0;j<m;j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                makewall(i, j, count+1);
                map[i][j] = 0;
            }
        }
    }
}