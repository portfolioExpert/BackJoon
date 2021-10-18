//문제 9019번 DSLR -> BFS
#include <string>
#include <queue>
#include <cstring>
bool visit[10001];
string bfs(int go, int goal){
    queue<pair<int,string>>q;
    q.push({go, ""});
    while(!q.empty()){
        int now = q.front().first;
        string str = q.front().second;
        q.pop();
        if(now == goal)
            return str;
        //D
        if(visit[(now * 2) % 10000] == 0){
            q.push({(now * 2) % 10000, str+'D'});
            visit[(now * 2) % 10000] = 1;
        }
        //S
        if(now == 0 && visit[9999] == 0){
            q.push({9999, str+'S'});
            visit[9999] = 1;
        }
        else if(now != 0 && visit[(now - 1)] == 0){
            q.push({(now - 1), str+'S'});
            visit[(now - 1)] = 1;
        }
        //L
        if(visit[(now * 10) % 10000 + now / 1000] == 0){
            q.push({(now * 10) % 10000 + now / 1000, str+'L'});
            visit[(now * 10) % 10000 + now / 1000] = 1;
        }
        //R
        if(visit[(now % 10) * 1000 + now / 10] == 0){
            q.push({(now % 10) * 1000 + now / 10, str+'R'});
            visit[(now % 10) * 1000 + now / 10] = 1;
        }
    }
    return "";
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        memset(visit, 0, sizeof(visit));
        int now, goal;
        cin >> now >> goal;
        cout << bfs(now, goal) << "\n";
    }
}