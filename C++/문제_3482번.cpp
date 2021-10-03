#include <iostream>
#include <algorithm>
using namespace std;

//문제 3482번
char input[1001][1001];
bool visit[1001][1001];
void dfs(int x ,int y, int leng);
int result = 0, x ,y, endx, endy;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, i ,j, k, chx = 0, chy = 0;
    cin >> t;
    for(k = 0;k<t;k++){
        cin >> y >> x;
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                cin >> input[i][j];
                if(input[i][j] == '.'){
                    chx = i;
                    chy = j;
                }
            }
        }
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                if(input[i][j] == '.'){
                    dfs(i,j, 0);
                    result = 0;
                    for(i=0;i<x;i++){
                        fill_n(visit[i], y, 0);
                    }
                    dfs(endx, endy, 0);
                    break;
                }
            }
        }
        cout << "Maximum rope length is " << result << ".\n";
        result = 0;
        for(i=0;i<x;i++){
            fill_n(visit[i], y, 0);
        }
    }
    return 0;
}
void dfs(int xs,int ys, int leng){
    if(visit[xs][ys] == 1)return;
    visit[xs][ys] = 1;
    int i;
    if(result < leng){
        result = leng;
        endx = xs;
        endy = ys;
    }
    for(i = 0; i<4;i++){
        int movx, movy;
        movx = xs + dx[i];
        movy = ys + dy[i];
        if(movx>=0 && movx<x && movy>=0 && movy<y && input[movx][movy] == '.' && visit[movx][movy] == 0){
            dfs(movx, movy, leng + 1);
        }
    }
}