//문제 14002번 가장 긴 증가하는 부분 수열4 ->DP
#include <vector>
vector<int>v[1001];
int dp[1001];
int main(){
    int n, i, j, result = -1, num[1001], big = 0;
    int maxind=1;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> num[i];
        dp[i] = 1;//자기 자신을 포함하기위해 전부 1로 시작
    }
    v[1].push_back(num[1]);
    for(i=1;i<=n;i++){
        int index = 0;
        for(j=1;j<i;j++){
            if(num[i]>num[j]){
                if(big <= dp[j]){
                    big = max(dp[j], big);//현재 위치보다 작은 것의 최댓값을 구한다
                    index = j;
                }
            }
        }
        dp[i] = big+1; //현재 위치 값까지 새어준다
        big = 0;//기준 값보다 작은 값이 있으므로 주기적으로 초기화
        result = max(result,dp[i]);//최댓값을 찾아준다
        v[i] = v[index];
        v[i].push_back(num[i]);
    }
    cout << result << "\n";
    int length = 0;
    for(int i = 1;i<=n;i++){
        if(length < v[i].size()){
            length = (int)v[i].size();
            maxind = i;
        }
    }
    for(int y : v[maxind])
        cout << y << " ";
}