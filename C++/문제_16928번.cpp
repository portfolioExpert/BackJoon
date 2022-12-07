#include <iostream>
#include <algorithm>
using namespace std;

//문제 16928번 뱀과 사다리 게임 -> BFS
#include <queue>
int road[101];
bool visit[101];
int result[101];
void bfs(){
    queue<int>q;
    q.push(1);
    result[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        //주사위 던지기
        for(int i = 1;i<=6;i++){
            int next = now + i;
            if(next <= 100 && visit[next] == 0){
                //사다리나 뱀이 있을 경우
                if(road[next] != 0){
                    if(visit[road[next]] == 1)
                        continue;
                    visit[road[next]] = 1;
                    q.push(road[next]);
                    result[road[next]] = result[now] + 1;
                }
                else{
                    if(visit[next] == 1)
                        continue;
                    visit[next] = 1;
                    q.push(next);
                    result[next] = result[now] + 1;
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n + m;i++){
        int from, to;
        cin >> from >> to;
        road[from] = to;
    }
    bfs();
    cout << result[100];
}