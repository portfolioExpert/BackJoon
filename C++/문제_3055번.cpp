#include <iostream>
#include <algorithm>
using namespace std;

//문제 3055
#include <queue>
queue <pair<int, int>> q;
queue <pair<int, int>> aniq;
char map[51][51];
int watervisit[51][51];
int anivisit[51][51];
int r, c, result, resultx, resulty;
void waterbfs();
void anibfs();
int dx[4] = {-1, 0, 1 , 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j;
    cin >> r >> c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j] == '*'){
                q.push({i, j});
                watervisit[i][j] = 1;
            }
            else if(map[i][j] == 'D'){
                resultx = i;
                resulty = j;
            }
            else if(map[i][j] == 'S'){
                aniq.push({i, j});
                anivisit[i][j] = 1;
            }
        }
    }
    waterbfs();
    anibfs();
    if(anivisit[resultx][resulty] != 0)
        cout << anivisit[resultx][resulty] - 1;
    else
        cout << "KAKTUS";
    return 0;
}
void waterbfs(){
    while(!q.empty()){
        int gx = q.front().first;
        int gy = q.front().second;
        q.pop();
        for(int i = 0; i < 4;i++){
            int gox = gx + dx[i];
            int goy = gy + dy[i];
            if(gox >= 0 && gox < r && goy >= 0 && goy < c && (map[gox][goy] == '.' || map[gox][goy] == 'S') && watervisit[gox][goy] == 0){
                q.push({gox, goy});
                watervisit[gox][goy] = watervisit[gx][gy] + 1;
            }
        }
    }
}
void anibfs(){
    while(!aniq.empty()){
        int gx = aniq.front().first;
        int gy = aniq.front().second;
        if(map[gx][gy] == 'D')return;
        aniq.pop();
        for(int i = 0; i < 4;i++){
            int gox = gx + dx[i];
            int goy = gy + dy[i];
            if(gox >= 0 && gox < r && goy >= 0 && goy < c && (map[gox][goy] == '.' || map[gox][goy] == 'D') && anivisit[gox][goy] == 0){
                anivisit[gox][goy] = anivisit[gx][gy] + 1;
                if(anivisit[gox][goy] < watervisit[gox][goy] || watervisit[gox][goy] == 0)
                    aniq.push({gox, goy});
            }
        }
    }
}