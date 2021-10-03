#include <iostream>
#include <algorithm>
using namespace std;

//문제 4963번
int map[51][51];
bool visit[51][51];
int dx[8] = {-1, 0, 1 , 0,-1, 1, -1 ,1};
int dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int n , m , result;
void dfs(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i ,j;
    while(1){
        cin >> m >> n;
        if(n == 0 && m == 0)break;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> map[i][j];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(map[i][j] == 1 && visit[i][j] == 0){
                    dfs(i, j);
                    result++;
                }
            }
        }
        cout << result << "\n";
        result = 0;
        for(i = 0;i<n;i++){
            fill_n(visit[i], m ,0);
        }
    }
    return 0;
}
void dfs(int x, int y){
    visit[x][y] = 1;
    for(int i=0;i<8;i++){
        int gx = x + dx[i];
        int gy = y + dy[i];
        if(gx>=0 && gx < n && gy>=0 && gy< m && visit[gx][gy] == 0 && map[gx][gy] == 1){
            visit[gx][gy] = 1;
            dfs(gx, gy);
        }
    }
}