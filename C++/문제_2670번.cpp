#include <iostream>
#include <algorithm>
using namespace std;

//문제 2670번
double dp[10001], result = -1;
int main(){
    int n, i;
    double num[10001];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    dp[0] = num[0];
    for(i=1;i<n;i++){
        dp[i] = max(dp[i - 1] * num[i], num[i]);
    }
    for(i=0;i<n;i++){
        result = max(dp[i], result);
    }
    cout.precision(3);
    cout << fixed << result;
    return 0;
}