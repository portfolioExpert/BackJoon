#include <iostream>
#include <algorithm>
using namespace std;

//문제 1697번
#include <queue>
queue <int>q;
int result, to;
int dx[3] = {-1, 1, 2};
void bfs(int x);
int visit[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int from;
    cin >> from >> to;
    q.push(from);
    bfs(from);
    cout << visit[to] - 1;
}
void bfs(int x){
    visit[x] = 1;
    while(!q.empty()){
        if(visit[to] != 0)
            return;
        int number = q.front();
        q.pop();
        for(int i = 0;i<3;i++){
            int go;
            if(dx[i] != 2)
                go = number+dx[i];
            else
                go = number * 2;
            if(go >= 0 && go <= 100000 && visit[go] == 0){
                visit[go] = visit[number] + 1;
                q.push(go);
            }
        }
    }
}