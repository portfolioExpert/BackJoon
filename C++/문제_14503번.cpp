#include <iostream>
#include <algorithm>
using namespace std;

//문제 14503번
int dx[4] = {-1, 0, 1 , 0};
int dy[4] = {0, 1, 0, -1};
int map[51][51], result, n , m;
bool visit[51][51];
void dfs(int x, int y, int po);
int main(){
    int i, j, po1, po2, look;
    cin >> n >> m;
    cin >> po1 >> po2 >> look;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    map[po1][po2] = 2;
    result++;
    dfs(po1, po2, look);
    cout << result;
    return 0;
}
void dfs(int x, int y, int po){
    for(int i = 0; i<4;i++){
        if(po == 1)//방향을 잡아준다
            po = 0;
        else if(po == 2)
            po = 1;
        else if(po == 3)
            po = 2;
        else if(po == 0)
            po = 3;
        int gx = x + dx[po];
        int gy = y + dy[po];
        if(map[gx][gy] == 0){
            map[gx][gy] = 2;//청소를 했다는 표시
            result++;
            dfs(gx, gy ,po);
        }
    }
    if(map[x - dx[po]][y - dy[po]] == 1){//뒤에가 벽일때는 후진을 못하므로 종료
        cout << result;
        exit(0);
    }
    else{
        dfs(x - dx[po], y - dy[po], po);
    }
}