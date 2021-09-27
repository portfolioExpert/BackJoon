//문제 2666번 벽장문의 이동 -> DP
#include <vector>
#include <cstring>
vector<int>v;
int n;
int dp[21][21][21];
int dfs(int index, int num1, int num2){
    if(index == v.size()){
        return 0;
    }
    if(dp[index][num1][num2] != -1)
        return dp[index][num1][num2];

    //다음 인덱스로 옮기면서 첫 번째로 타깃을 옮길때, 두번째로 타깃을 옮길때 각각 위치에 거리 차이 만큼 더해주고 최솟값을 구한다.
    return dp[index][num1][num2] = min(dfs(index + 1, v[index], num2) + abs(num1 - v[index]), dfs(index + 1, num1, v[index]) + abs(num2 - v[index]));
}
int main(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    int num1 ,num2;
    cin >> num1 >> num2;
    int target;
    cin >> target;
    for(int i = 0;i<target;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cout << dfs(0, num1, num2);
}