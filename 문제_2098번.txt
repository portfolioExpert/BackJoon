#include <iostream>
#include <algorithm>
using namespace std;

//문제 2098번
int cost[16][16], n;
int dp[16][1<<16];
int fx(int here, int visit);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> cost[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));//-1로 전부 초기화
    cout << fx(0, 1);
    return 0;
}
int fx(int here, int visit){
    if(visit == (1 << n) - 1){
        if(cost[here][0] != 0)//값이 0이 아니면 값을 리턴
            return cost[here][0];
        return 987654321;
    }
    int &result = dp[here][visit];
    if(result != -1)//dp값이 있으면 리턴해준다
        return result;
    result = 987654321;
    for(int next = 0; next<n;next++){
        if(visit & (1<<next) || cost[here][next] == 0)//이미 방문했으면 통과
            continue;
        int val = cost[here][next] + fx(next, visit + (1 << next));//방문 안한곳 계속 방문
        result = min(result, val);//dp값을 최소로 해준다
    }
    return result;//dp값을 리턴
}