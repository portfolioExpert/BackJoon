#include <iostream>
#include <algorithm>
using namespace std;

//문제 1967번 트리 지름
#include <vector>
vector <pair<int,int>> v[10001];
int result = 0, endpoint;
bool visit[10001];
void dfs(int from, int length);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, num1, num2, i, weight;
    cin >> n;
    for(i = 0;i<n-1;i++){
        cin >> num1 >> num2 >> weight;
        v[num1].push_back({num2, weight});
        v[num2].push_back({num1, weight});
    }
    dfs(1, 0);
    result = 0;
    fill_n(visit, 10001, 0);
    dfs(endpoint , 0);
    cout << result;
    return 0;
}
void dfs(int from, int length){
    int i = 0;
    if(visit[from] == 1)return;
    visit[from] = 1;
    if(result < length){
        result = length;
        endpoint = from;
    }
    for(i = 0; i<v[from].size();i++){
        dfs(v[from][i].first, length + v[from][i].second);
    }
}