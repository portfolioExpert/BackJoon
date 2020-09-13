#include <iostream>
#include <algorithm>
using namespace std;

//문제 1652번
#include <queue>
queue <pair<int,int>> q1;
queue <pair<int, int>> q2;
char map[101][101];
bool visit[101][101];
int n, result1, result2;
void BFS(int x, int y, char ch);
int main(){
    int i , j;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 'X')visit[i][j] = 1;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(visit[i][j] == 0 && map[i][j] == '.')
                BFS(i, j, 'l');
        }
    }
    for(i=0;i<n;i++){
        fill_n(visit[i], 100, 0);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(visit[j][i] == 0 && map[j][i] == '.')
                BFS(j, i, 'c');
        }
    }
    cout << result1 << " " << result2;
    return 0;
}
void BFS(int x, int y, char ch){
    int cnt = 1;
    visit[x][y] = 1;
    if(ch == 'l'){
        q1.push({x,y});
        while(!q1.empty()){
            int dx, dy;
            dx = q1.front().first;
            dy = q1.front().second;
            q1.pop();
            if(dy+1>= 0 && dy+1 < n && map[dx][dy+1] == '.' && visit[dx][dy+1] == 0){
                q1.push({dx, dy+1});
                visit[dx][dy+1] = 1;
                cnt++;
            }
        }
        if(cnt >= 2)result1++;
    }
    else{
        q2.push({x, y});
        while(!q2.empty()){
            int dx, dy;
            dx = q2.front().first;
            dy = q2.front().second;
            q2.pop();
            if(dx+1>=0 && dx+1 < n && map[dx+1][dy] == '.' && visit[dx+1][dy] == 0){
                q2.push({dx+1 , dy});
                visit[dx+1][dy] = 1;
                cnt++;
            }
        }
        if(cnt >= 2)result2++;
    }
}