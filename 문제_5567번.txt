#include <iostream>
#include <algorithm>
using namespace std;

//문제 5567번
#include <vector>
#include <queue>
queue<pair<int, int>>q;
vector<int>v[501];
bool visit[501];
int result;
void bfs();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    for(int i = 0;i<t;i++){
        int num1, num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    bfs();
    cout << result;
}
void bfs(){
    q.push({1, 0});
    visit[1] = 1;
    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int y : v[now]){
            if(cnt + 1> 2)
                continue;
            if(visit[y] == 0){
                visit[y] = 1;
                q.push({y, cnt + 1});
                result++;
            }
        }
    }
}