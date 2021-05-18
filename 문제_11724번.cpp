#include <iostream>
#include <algorithm>
using namespace std;

//문제 11724번
#include <vector>
vector <int> v[1001];
bool visit[1001];
void DFS(int x);
int main(){
    int n, m, i, point1, point2, cnt = 0;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> point1 >> point2;
        v[point1].push_back(point2);
        v[point2].push_back(point1);
    }
    for(i=1;i<=n;i++){
        if(visit[i] == 0){
            DFS(i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
void DFS(int x){
    visit[x] = 1;
    for(int y : v[x]){
        if(visit[y] == 0){
            visit[y] = 1;
            DFS(y);
        }
    }
}