#include <iostream>
#include <algorithm>
using namespace std;

//문제 3184번
#include <queue>
queue <pair<int, int>> q;
char ch[251][251];
bool visit[251][251];
void bfs(int x, int y);
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int v ,o, n , m;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int totalv = 0, totalk = 0, i, j;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> ch[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if((ch[i][j] == 'v' || ch[i][j] == 'o') && visit[i][j] == 0){
                bfs(i,j);
                if(o>v)
                    v = 0;
                else
                    o = 0;
                totalv += v;
                totalk += o;
                v = 0;
                o = 0;
            }
        }
    }
    cout << totalk << " " << totalv;
    return 0;
}
void bfs(int x, int y){
    if(ch[x][y] == 'v')
        v++;
    else if(ch[x][y] == 'o')
        o++;
    q.push({x, y});
    visit[x][y] = 1;
    while(!q.empty()){
        int pox, poy;
        pox = q.front().first;
        poy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int gox = pox + dx[i];
            int goy = poy + dy[i];
            if(gox>=0 && gox < n && goy >=0 && goy < m && visit[gox][goy] == 0 && ch[gox][goy] != '#'){
                visit[gox][goy] = 1;
                if(ch[gox][goy] == 'v')
                    v++;
                else if(ch[gox][goy] == 'o')
                    o++;
                q.push({gox, goy});
            }
        }
    }
}