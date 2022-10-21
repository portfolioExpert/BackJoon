//문제 1563번 개근상 -> DP TOPDOWN
//dp[일자][결석횟수][지각횟수]
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3][2];
int n;
int topdown(int day, int absent, int late){
    //지각 2번이면
    if(late == 2)
        return 0;
    if(absent == 3)
        return 0;
    if(day > n)
        return 1;
    int &save = dp[day][absent][late];
    if(save != -1)
        return save;
    return save = (topdown(day + 1, 0, late) + topdown(day+1, absent + 1, late) + topdown(day + 1, 0, late + 1)) % 1000000;
}
int main(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << topdown(1, 0, 0);
}