#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 7562번
#include <queue>
queue <pair<int,int>> q;
int visit[301][301];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
void BFS(int l, int t, int s);
int main(){
    int test, n, i, fromx, fromy, tox,toy;
    cin >> test;
    for(i=0;i<test;i++){
        cin >> n >> fromx >> fromy >> tox >> toy;
        q.push({fromx, fromy});
        visit[fromx][fromy] = 0;
        BFS(n, tox, toy);
        if(fromx == tox && fromy == toy){
            cout << 0 << "\n";
        }
        else
            cout << visit[tox][toy] << "\n";
        for(j=0;j<n;j++){
            fill_n(visit[j], n, 0);
        }
        fill_n(visit[0], n*n, 0);
    }
}
void BFS(int l, int t, int s){
    while(!q.empty()){
        if(visit[t][s] != 0)break; //2번째 case에선 왜 24가 나올까?
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1 >= 0 && y1 >= 0 && x1 < l && y1 < l && visit[x1][y1] == 0){
                visit[x1][y1] = visit[x][y] + 1;
                q.push({x1,y1});
            }
        }
    }
}