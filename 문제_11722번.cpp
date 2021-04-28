#include <iostream>
#include <algorithm>
using namespace std;

//문제 11722번
int dp[1001];
int main(){
    int n, i, j, result = -1, num[1001], big = 0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> num[i];
        dp[i] = 1;//자기 자신을 포함하기위해 전부 1로 시작
    }
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            if(num[i]<num[j]){
                big = max(dp[j], big);//현재 위치보다 작은 것의 최댓값을 구한다
            }
        }
        dp[i] = big+1; //현재 위치 값까지 새어준다
        big = 0;//big에 dp[j]최댓값이 들어가도록 하기위해서 항상 0으로 고정
        result = max(result,dp[i]);//최댓값을 찾아준다
    }
    cout << result;
    return 0;
}