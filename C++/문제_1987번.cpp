#include <iostream>
#include <algorithm>
using namespace std;

//문제 1987번
bool visit[26];
int dx[4] = {-1, 0, 1 , 0};
int dy[4] = {0, 1, 0, -1};
int r ,c, result = 1, value = 1;
char map[21][21];
void dfs(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i , j;
    cin >> r >> c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> map[i][j];
        }
    }
    visit[map[0][0] - 'A'] = 1;
    dfs(0, 0);
    cout << value;
}
void dfs(int x, int y){
    for(int i = 0; i<4;i++){
        int gox = x + dx[i];
        int goy = y + dy[i];
        if(gox >= 0 && gox < r && goy>= 0 && goy < c && visit[map[gox][goy] - 'A'] == 0){
            result++;
            value = max(value, result);
            visit[map[gox][goy] - 'A'] = 1;
            dfs(gox, goy);
            result--;
            visit[map[gox][goy] - 'A'] = 0;
        }
    }
}