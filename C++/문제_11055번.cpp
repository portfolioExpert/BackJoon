#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 11055번
int dp[1001];
int main(){
    int n, num[1001], i, j, result = -1, big = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
        dp[i] = num[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(num[i] > num[j]){
                big = max(big, dp[j]);
            }
        }
        dp[i]+=big;
        result = max(result, dp[i]);
        big = 0;
    }
    cout << result;
    return 0;
}