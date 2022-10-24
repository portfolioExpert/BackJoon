#include <iostream>
#include <algorithm>
using namespace std;

//문제 2615번 오목 -> 브루트포스
#include <vector>
int map[20][20];
bool visit[20][20];
int dx[4] = {0, 1, 1 ,-1};
int dy[4] = {1, 1, 0 ,1};
bool flag = false;
void dfs(int x, int y, int number, int index, int cnt, vector<pair<int,int>>v){
    visit[x][y] = 1;
    //탐색
    for(int i = 0;i<4;i++){
        int gox = x + dx[i];
        int goy = y + dy[i];
        //같은 방향만 진행
        if(gox >= 1 && gox <= 19 && goy >= 1 && goy <= 19 && map[gox][goy] == number && i == index){
            v.push_back({goy, gox});
            dfs(gox, goy, number, index, cnt + 1, v);
        }
    }
    visit[x][y] = 0;
    //5개일 경우
    if(cnt == 5){
        //6목 체크
        //처음값 전 위치
        int gox = x - 5 * dx[index];
        int goy = y - 5 * dy[index];
        //마지막 값 다음 위치
        int gx = x + dx[index];
        int gy = y + dy[index];

        sort(v.begin(),v.end());
        
        //안쪽 범위 탐색
        //처음값 전이 틀리고
        if(gox >= 1 && gox <= 19 && goy >= 1 && goy <= 19 && map[gox][goy] != number ){
            //마지막 값 다음 위치가 틀리면
            if(gx >= 1 && gx <= 19 && gy >= 1 && gy <= 19 && map[gx][gy] != number){
                cout << number << "\n";
                cout << v[0].second << " " << v[0].first;
                exit(0);
            }
            //아예 나갔다면
            else if(gx < 1 || gx > 19 || gy < 1 || gy > 19){
                cout << number << "\n";
                cout << v[0].second << " " << v[0].first;
                exit(0);
            }
        }
        //처음이 끝 좌표 일 경우
        else if(gox < 1 || gox > 19 || goy < 1 || goy > 19){
            //반대쪽이 끝이 아닐 경우
            if(gx >= 1 && gx <= 19 && gy >= 1 && gy <= 19 && map[gx][gy] != number){
                cout << number << "\n";
                cout << v[0].second << " " << v[0].first;
                exit(0);
            }
            //반대쪽이 끝일 경우
            if(x == 1 || x == 19 || y == 1 || y == 19){
                if((gx < 1 || gx > 19 || gy < 1 || gy > 19) && map[x][y] == number){
                    cout << number << "\n";
                    cout << v[0].second << " " << v[0].first;
                    exit(0);
                }
            }
        }
    }
}
int main(){
    for(int i = 1;i<=19;i++){
        for(int j = 1;j<=19;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 1;i<=19;i++){
        for(int j = 1;j<=19;j++){
            if(!flag && map[i][j] != 0){
                for(int k = 0;k<4;k++){
                    if(!visit[i][j]){
                        vector<pair<int,int>>v;
                        v.push_back({j, i});
                        dfs(i, j, map[i][j], k, 1, v);
                    }
                }
            }
        }
    }
    if(!flag)
        cout << 0;
}