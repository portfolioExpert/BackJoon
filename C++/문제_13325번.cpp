#include <iostream>
#include <algorithm>
using namespace std;

//문제 13325 이진트리 -> 트리 DP
int dp[2100000];
int n;
int height = 1;
int result = 0;
int topdown(int now){
    //리프노드
    if(now >= height)
        return 0;

    //범위 조정
    if(now * 2 > 2100000)
        return 0;
    int cache = 0;
    int left = topdown(now * 2) + dp[now * 2];
    int right = topdown(now * 2 + 1) + dp[now * 2 + 1];

    cache = max(left, right);
    result+=cache;
    return cache;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n+1;i++){
        height *=2;
    }

    for(int i = 2;i<=height - 1;i++){
        cin >> dp[i];
    }
    cout << topdown(1) + result;
}