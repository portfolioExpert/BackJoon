#include <iostream>
#include <algorithm>
using namespace std;

//문제 2293번, 동전 채워넣기 식 -> 1로 채울 수 있는 것, 2로 채울 수 있는 것 등등
int num[101];
int dp[10001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j = num[i];j<=k;j++){
            if(j-num[i] >= 0){
                dp[j] = dp[j]+dp[j-num[i]];
            }
        }
    }
    cout << dp[k];
}