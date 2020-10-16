#include <iostream>
#include <algorithm>
using namespace std;

//문제 2660번
#include <vector>
#include <queue>
queue <int> q;
vector <int> v[51];
int dp[51];
int visit[51];
int result = 2147483647;
void bfs(int x);
int main(){
    int n, i, cnt = 0;
    cin >> n;
    while(true){
        int num1, num2;
        cin >> num1 >> num2;
        if(num1 == -1 && num2 == -1)break;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    for(i=1;i<=n;i++){
        q.push(i);
        bfs(i);
        fill_n(visit, 51, 0);
    }
    cout << result << " ";
    for(i=1;i<=n;i++){
        if(result == dp[i]){
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(i=1;i<=n;i++){
        if(result == dp[i]){
            cout << i << " ";
        }
    }
    return 0;
}
void bfs(int x){
    visit[x] = 1;
    while(!q.empty()){
        int go = q.front();
        q.pop();
        for(int y : v[go]){
            if(visit[y] == 0){
                visit[y] = visit[go] + 1;
                q.push(y);
                dp[x] = visit[y] - 1;
            }
        }
    }
    result = min(result, dp[x]);
}