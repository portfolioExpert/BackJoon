#include <iostream>
#include <algorithm>
using namespace std;

//문제 4811번 알약 -> DP
//dp[전체 개수][반쪽 개수]
#include <cstring>
typedef long long ll;
ll dp[31][31];
ll topdown(int whole, int half){
    //다 먹은 경우
    if(whole == 0 && half == 0){
        return 1;
    }
    ll &save = dp[whole][half];

    if(save != -1)
        return dp[whole][half];
    dp[whole][half] = 0;
    //전체 먹을 것이 있다면
    if(whole > 0){
        dp[whole][half] += topdown(whole - 1, half + 1);
    }
    //반쪽 먹을 것이 있다면
    if(half > 0){
        dp[whole][half] += topdown(whole, half - 1);
    }
    return dp[whole][half];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    topdown(30, 0);
    while(1){
        int t;
        cin >> t;
        if(t == 0)
            break;
        cout << dp[t][0] << "\n";
    }
}