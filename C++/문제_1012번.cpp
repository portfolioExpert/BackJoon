#include <iostream>
#include <algorithm>
using namespace std;

//문제 1012번
bool visit[51][51];
void dfs(int x, int y, int maxx, int maxy);
int dx[4] = {0 ,0 , 1, -1};
int dy[4] = {-1, 1, 0, 0};
int map[51][51];
int main(){
    int n, i, t, m, po , j, result = 0, num1, num2, k;
    cin >> t;
    for(i=0;i<t;i++){
        cin >> n >> m >> po;
        for(j=0;j<po;j++){
            cin >> num1 >> num2;
            map[num2][num1] = 1;
        }
        for(j=0;j<m;j++){
            for(k=0;k<n;k++){
                if(visit[j][k] == 0 && map[j][k] == 1){
                    dfs(j, k, m, n);
                    result++;
                }
            }
        }
        for(j=0;j<m;j++){
            fill_n(map[j], n, 0);
        }
        for(j=0;j<m;j++){
            fill_n(visit[j], n, 0);
        }
        cout << result << "\n";
        result = 0;
    }
}
void dfs(int x, int y, int maxx, int maxy){
    visit[x][y] = 1;
    for(int i = 0;i<4;i++){
        int dix, diy;
        dix = x + dx[i];
        diy = y + dy[i];
        if(dix >= 0 && dix <= maxx && diy >=  0 && diy <= maxy && visit[dix][diy] == 0 && map[dix][diy] == 1)
            dfs(dix, diy, maxx, maxy);
    }
}