#include <iostream>
#include <algorithm>
using namespace std;

//문제 2644번
#include <vector>
#include <queue>
queue <int> q;
vector <int> v[101];
int dp[101];
int n, human1, human2, result;
void bfs(int x);
int main(){
    int i, t;
    cin >> n >> human1 >> human2 >> t;
    for(i=0;i<t;i++){
        int num1, num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    fill_n(dp, 101, -1);
    bfs(human1);
    cout << dp[human2];
}
void bfs(int x){
    q.push(x);
    dp[x] = 0;
    while(!q.empty()){
        int go = q.front();
        q.pop();
        for(int y : v[go]){
            if(dp[y] == -1){
                q.push(y);
                dp[y] = dp[go] + 1;
            }
        }
    }
}