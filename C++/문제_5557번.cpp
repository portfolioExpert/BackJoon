//문제 5557번 1학년 -> DP topdown 이용
#include <cmath>
typedef long long ll;
ll dp[101][21];
int num[101];
int n;
ll topdown(int idx, int now){
    //기저
    if(now > 20 || now < 0)
        return 0;
    //도착했을때
    if(idx == n - 2)
        return now == num[n-1] ? 1 : 0;
    //이미 방문했다면 값을 리턴
    if(dp[idx][now] != -1)
        return dp[idx][now];
    //0에 num[n-1] 인덱스에 총 개수가 모인다
    dp[idx][now] = 0;

    return dp[idx][now] += topdown(idx + 1,num[idx + 1] + now) + topdown(idx + 1, now - num[idx + 1]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << topdown(0, num[0]) << "\n";
    return 0;
}