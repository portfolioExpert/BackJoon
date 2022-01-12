//문제 10819번 차이를 최대로 -> 백트래킹
#include <vector>
#include <cmath>
vector<int>v;
int n;
int num[9];
int result = 0;
bool visit[9];
void dfs(int cnt){
    if(cnt == n){
        int sum = 0;
        for(int i = 0;i<v.size() - 1;i++){
            sum += abs(v[i] - v[i+1]);
        }
        result = max(result, sum);
        return;
    }
    for(int i = 0;i<n;i++){
        if(visit[i] == 0){
            v.push_back(num[i]);
            visit[i] = 1;
            dfs(cnt + 1);
            visit[i] = 0;
            v.pop_back();
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    dfs(0);
    cout << result;
}