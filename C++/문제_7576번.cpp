#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 7576번
#include <queue>
queue <pair<int, int>> q;
int dx[4] = {0, 0, 1, -1};//좌표 설정을 위해
int dy[4] = {1, -1, 0, 0};
int infor[1001][1001];//토마토 정보
void BFS(int t, int s);
int main(){
    int n, m, i, j, cnt = 0, result = -1;
    cin >> m >> n;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> infor[i][j];
            if(infor[i][j] == 1){
                cnt++;
                q.push({i,j});
            }
        }
    }
    BFS(n,m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            result = max(result,infor[i][j]);
            if(infor[i][j] == 0){
                result = 0;
                break;
            }
        }
        if(result == 0)break;
    }
    cout << result -1;
    return 0;
}
void BFS(int t, int s){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int statex, statey;
            statex = x + dx[i];
            statey = y + dy[i];
            if(statex >= 0 && statey >= 0 &&infor[statex][statey] == 0 && statex < t && statey < s){
                infor[statex][statey] =  infor[x][y] + 1;//dp를 이용하여 날짜를 구함
                q.push({statex,statey});
            }
        }
    }
}