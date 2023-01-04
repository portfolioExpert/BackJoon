#include <iostream>
#include <algorithm>
using namespace std;

//문제 11559번 Puyo Puyo ->bfs, 구현
//먼저 어떻게 풀어야할지 설계를 하고 코드를 짜자.
//1. 전체 4개 이상이 되는 공간을 탐색해서 넣어주고
//2. 터뜨리고 블록을 내려주고
//3. 방문초기화
#include <vector>
#include <queue>
#include <stack>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0 ,0, 1, -1};
char map[13][7];
int result = 0;
int cnt = 0;
bool visit[13][7]; //4개 이상만 방문하는 것
vector<pair<int,int>>visited;//4개이상인 부분의 좌표
//4개이상인 부분 찾기
int bfs(int x, int y){
    int res = 1;
    queue<pair<int,int>>q;
    q.push({x, y});
    visited.push_back({x, y});
    char ch = map[x][y];
    visit[x][y] = 1;
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < 12 && gy >= 0 && gy < 6 && map[gx][gy] == ch && visit[gx][gy] == 0){
                visit[gx][gy] = 1;
                visited.push_back({gx, gy});
                q.push({gx, gy});
                res++;
            }
        }
    }
    return res;
}
//내리기
void down(){
    //터진 곳 표시
    for(int i = 0;i<visited.size();i++){
        map[visited[i].first][visited[i].second] = '/';
    }
    //왼쪽 아래부터 체크
    for(int i = 11;i>=0;i--){
        for(int j = 0;j<6;j++){
            //펑 표시가 되있다면 위로 몇칸을 내려야하는지 체크
            if(map[i][j] == '/'){
                stack<char>s;
                //내려오면서 스택 넣기
                for(int k = 0;k<12;k++){
                    if(map[k][j] == '/'){
                        continue;
                    }
                    s.push(map[k][j]);
                    map[k][j] = '.';
                }
                //올라오면서 스택 빼주기
                for(int k = 11;k>=0;k--){
                    if(s.empty())
                        break;
                    map[k][j] = s.top();
                    s.pop();
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    for(int i = 0;i<12;i++){
        for(int j = 0;j<6;j++){
            cin >> map[i][j];
        }
    }
    while(1){
        //터졌는지 체크
        bool flag = true;
        //아래부터 탐색
        for(int i = 11;i>=0;i--){
            cnt = 0;
            for(int j = 0;j<6;j++){
                if(map[i][j] == '.')
                    cnt++;
                //터뜨려야한다.
                if(visit[i][j] == 0 && map[i][j] != '.'){
                    int pung = bfs(i, j);
                    if(pung >= 4){
                        flag = false;
                    }
                    else{
                        //4개 미만은 방문 초기화
                        for(int i = 0;i<pung;i++){
                            visited.pop_back();
                        }
                    }
                }
            }
            //한 줄이 모두 . 이면 탐색 안해도 된다.
            if(cnt == 6)
                break;
        }
        down();
        //터질게 없으면 끝
        if(flag)
            break;
        result++;
        visited.clear();
        memset(visit, 0 ,sizeof(visit));
    }
    cout << result;
}ㅁ