//문제 3197번 백조의 호수
#include <queue>
#include <vector>
vector<pair<int,int>>v;
queue<pair<int,int>> waterq;
queue<pair<int,int>> nextwater;
queue<pair<int,int>> swanq;
queue<pair<int,int>> nextswan;
int r, c;
bool meet = false;
char map[1501][1501];
bool visit[1501][1501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//백조가 움직이는 것
void swanbfs(){
    while(!swanq.empty() && !meet){
        int gox = swanq.front().first;
        int goy = swanq.front().second;
        swanq.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < r && gy >= 0 && gy < c && visit[gx][gy] == 0){
                if(map[gx][gy] == '.')//물이면 움직이고
                    swanq.push({gx, gy});
                else if(map[gx][gy] == 'L'){//백조면 만났으므로 종료
                    meet = true;
                    return ;
                }
                else{//얼음이면 다음에 백조가 갈 수 있으므로 넣어두고
                    nextswan.push({gx, gy});
                }
                visit[gx][gy] = 1;//방문 처리
            }
        }
    }
}
//물이 움직이면서 다음에 물이 되는 것을 따로 큐에 저장
void waterbfs(){
    while(!waterq.empty()){
        int gox = waterq.front().first;
        int goy = waterq.front().second;
        waterq.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            //다음 물이 되는곳을 넣어주는 작업
            if(gx >= 0 && gx < r && gy >= 0 && gy < c && map[gx][gy] == 'X'){
                map[gx][gy] = '.';
                nextwater.push({gx, gy});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    int day = 0;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j] != 'X')
                waterq.push({i,j});
            if(map[i][j] == 'L')
                v.push_back({i,j});
        }
    }
    swanq.push({v[0].first, v[0].second});
    visit[v[0].first][v[0].second] = 1;
    while(!meet){
        swanbfs();
        if(meet){
            break;
        }
        waterbfs();
        swanq = nextswan;
        waterq = nextwater;
        day++;
        //큐를 비어주는 작업
        while(!nextwater.empty())
            nextwater.pop();
        while(!nextswan.empty())
            nextswan.pop();
    }
    cout << day;
}