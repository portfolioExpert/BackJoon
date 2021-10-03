#include <iostream>
#include <algorithm>
using namespace std;

//문제 9251번
#include <string>
#include <cstring>
int dp[1001][1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string str1, str2;
    int i, j;
    cin >> str1 >> str2;
    for(i=1;i<=str1.size();i++){
        for(j=1;j<=str2.size();j++){
            if(str1[i-1] == str2[j-1])//같으면 대각선 값에서 1을 더해주고 이유는 바로 전 문자열 상태 이기때문
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);//같지않으면 왼쪽 위쪽 중 큰값으로 넣어준다
        }
    }
    cout << dp[str1.size()][str2.size()];
}