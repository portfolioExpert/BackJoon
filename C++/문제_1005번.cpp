//문제 1005번
#include <vector>
#include <queue>
#include <cstring>
int num[1001], dp[1001];
vector<int>node[1001];
int topdown(int n);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<1000;i++){
            node[i].clear();
        }
        int n, k;
        cin >> n >> k;
        for(int i = 1;i<=n;i++){
            cin >> num[i];
        }
        for(int i = 1;i<=k;i++){
            int num1, num2;
            cin >> num1 >> num2;
            node[num2].push_back(num1);
        }
        int w;
        cin >> w;
        cout << topdown(w) << "\n";
    }
}
int topdown(int n){
    if(node[n].size() == 0){
        return dp[n] = num[n];
    }
    if(dp[n] != -1)
        return dp[n];
    for(int y : node[n]){
        if(dp[y] == -1){
            dp[n] = max(topdown(y) + num[n], dp[n]);
        }
        else{
            dp[n] = max(dp[n], num[n] + dp[y]);
        }
    }
    return dp[n];
}