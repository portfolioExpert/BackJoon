#include <iostream>
#include <algorithm>
using namespace std;

//문제 2583번
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int map[101][101];
bool visit[101][101];
int result[10001];
int cnt, n , m, t, total;
void dfs(int x, int y);
int main(){
    int i, j, k, num1, num2, num3, num4, count = 0;
    cin >> n >> m >> t;
    for(i=0;i<t;i++){
        cin >> num1 >> num2 >> num3 >> num4;
        for(j = num2 + 1; j <= num4;j++){
            for(k = num1 + 1; k <= num3;k++){
                map[n + 1 - j][k] = 1;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(map[i][j] == 0 && visit[i][j] == 0){
                total = 1;
                dfs(i, j);
                result[count++] = total;
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    sort(result, result+ count);
    for(i=0;i<count;i++){
        cout << result[i] << " ";
    }
    return 0;
}
void dfs(int x, int y){
    visit[x][y] = 1;
    for(int i = 0;i <4;i++){
        int gx = x + dx[i];
        int gy = y + dy[i];
        if(gx >= 1 && gx <= n && gy>=1 && gy<=m && visit[gx][gy] == 0 && map[gx][gy] == 0){
            total++;
            dfs(gx, gy);
        }
    }
}
