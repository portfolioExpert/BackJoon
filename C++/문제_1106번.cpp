//문제 1106번 호텔 -> DP
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int c, n;
    int dp[100001];
    for(int i = 0;i<100001;i++){
        dp[i] = 987654321;
    }
    vector<pair<int,int>>v;
    cin >> c >> n;
    for(int i = 0;i<n;i++){
        int cost, able;
        cin >> cost >> able;
        v.push_back({cost, able});
        for(int j = able;j>=0;j--){
            dp[j] = min(dp[j], cost);
        }
    }
    for(int i = 0;i<=100000;i++){
        for(int j = 0;j<v.size();j++){
            int cost = v[j].first;
            int able = v[j].second;
            if(able + i > 100000){
                continue;
            }
            dp[i + able] = min(dp[i+able], dp[i] + cost);
        }
    }
    cout << dp[c];
}