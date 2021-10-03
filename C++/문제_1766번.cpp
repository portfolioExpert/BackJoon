//문제 1766번 문제집 -> 위상정렬로 풀이
//작은 번호부터 풀어야하는 것을 pq를 이용
#include <vector>
#include <queue>
priority_queue<int>pq;
vector<int>v[32001];
int visit[32001];
int dp[32001];
vector<int>answer;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        visit[num2]++;
    }
    for(int i = 1;i<=n;i++){
        if(visit[i] == 0)
            pq.push(-i);
    }
    while(!pq.empty()){
        int go = -pq.top();
        pq.pop();
        answer.push_back(go);
        for(int y : v[go]){
            visit[y]--;
            if(visit[y] == 0)
                pq.push(-y);
        }
    }
    for(int y : answer)
        cout << y << " ";
}