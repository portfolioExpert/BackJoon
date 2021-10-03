#include <iostream>
#include <algorithm>
using namespace std;

//문제 1912번
int dp[100001];//n번째 까지의 합
int main(){
    int i , n, num[100001], maxval = -1001;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    dp[0] = num[0];//처음 값은 무조건 최고값이므로 담는다
    for(i=1;i<n;i++){
        dp[i] = max(dp[i-1] + num[i], num[i]);//i번째 합과 다음 숫자를 비교하여 더 큰것으로 둔다
        maxval = max(dp[i], maxval);//i번째 합과 최고값을 비교한다
    }
    cout << max(maxval,dp[0]);//초깃값과 비교
    return 0;
}