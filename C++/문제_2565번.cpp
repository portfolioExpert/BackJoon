#include <iostream>
#include <algorithm>
using namespace std;

//문제 2565번 전깃줄 -> DP, 가장 긴 증가하는 수열
int arr[501];
int dp[501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    int maxval = 0, maxNum = 0;
    for(int i = 0;i<n;i++){
        int from, to;
        cin >> from >> to;
        arr[from] = to;
        dp[from] = 1;
        maxNum = max(maxNum, max(to,from));
    }
    //첫번째 배열
    int big = 0;
    for(int i = 1;i<=maxNum;i++){
        if(dp[i] == 0)
            continue;
        for(int j = 1;j<i;j++){
            if(arr[i] > arr[j]){
                if(big <= dp[j])
                    big = max(dp[j], big);
            }
        }
        dp[i] = big + 1;
        big = 0;
        maxval = max(maxval, dp[i]);
    }
    cout << n - maxval;
}