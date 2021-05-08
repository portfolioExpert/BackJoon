#include <iostream>
#include <algorithm>
using namespace std;

//문제 2606
#include <vector>
#include <queue>
queue <int> q;
vector <int> v[101];
bool visit[101];
void BFS(int x);
int total = 0;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, node, num1, num2, i;
    cin >> n >> node;
    for(i=0;i<node;i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    BFS(1);
    cout << total;
    return 0;
}
void BFS(int x){
    visit[x] = 1;
    q.push(x);
    while(!q.empty()){
        int go = q.front();
        q.pop();
        for(int y : v[go]){
            if(visit[y] == 0){
                q.push(y);
                visit[y] = 1;
                total++;
            }
        }
    }
}