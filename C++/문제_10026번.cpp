#include <iostream>
#include <algorithm>
using namespace std;

//문제 10026번
bool visit[101][101];
char map1[101][101], map2[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}, n;
void DFS1(int x, int y);
void DFS2(int x, int y);
int main(){
    int i, j, result1 = 0, result2 = 0;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> map1[i][j];
            if(map1[i][j] == 'G')
                map2[i][j] = 'R';
            else
                map2[i][j] = map1[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(visit[i][j] == 0){
                DFS1(i,j);
                result1++;
            }
        }
    }
    for(i=0;i<n;i++){
        fill_n(visit[i], 100, 0);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(visit[i][j] == 0){
                DFS2(i,j);
                result2++;
            }
        }
    }
    cout << result1 << " " << result2;
    return 0;
}
void DFS1(int x, int y){
    visit[x][y] = 1;
    for(int i = 0;i<4;i++){
        int po1, po2;
        po1 = x + dx[i];
        po2 = y + dy[i];
        if(po1 >= 0 && po1 <= n && po2 >= 0 && po2 <= n && visit[po1][po2] == 0 && map1[x][y] == map1[po1][po2]){
            visit[po1][po2] = 1;
            DFS1(po1, po2);
        }
    }
}
void DFS2(int x, int y){
    visit[x][y] = 1;
    for(int i = 0;i<4;i++){
        int po1, po2;
        po1 = x + dx[i];
        po2 = y + dy[i];
        if(po1 >= 0 && po1 <= n && po2 >= 0 && po2 <= n && visit[po1][po2] == 0 && map2[x][y] == map2[po1][po2]){
            visit[po1][po2] = 1;
            DFS2(po1, po2);
        }
    }
}