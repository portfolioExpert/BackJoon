#include <iostream>
#include <algorithm>
using namespace std;

//문제 11403번
#include <vector>
#include <queue>
queue <int> q;
vector <int> v[101];
bool visit[101];
int map[101][101];
void BFS(int x);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, j, num;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> num;
            if(num == 1){
                v[i].push_back(j);//한방향으로 이어줌
            }
        }
    }
    for(i=0;i<n;i++){
        BFS(i);
        fill_n(visit, 100, 0);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
void BFS(int x){
    q.push(x);
    while(!q.empty()){
        int po = q.front();
        q.pop();
        for(int y : v[po]){
            if(visit[y] == 0){
                q.push(y);
                visit[y] = 1;
                map[x][y] = 1;
            }
        }
    }
}