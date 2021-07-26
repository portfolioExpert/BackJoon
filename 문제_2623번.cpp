//문제 2623번 음악프로그램 -> 위상정렬
#include <vector>
#include <queue>
vector<int>v[1001];
int visit[1001];
queue<int>q;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int cnt;
        cin >> cnt;
        int before = 0;
        for(int j = 0;j<cnt;j++){
            int next;
            cin >> next;
            if(before == 0){
                before = next;
                continue;
            }
            v[before].push_back(next);
            visit[next]++;
            before = next;
        }
    }
    for(int i = 1;i<=n;i++){
        if(visit[i] == 0){
            q.push(i);
        }
    }
    vector<int>answer;
    while(!q.empty()){
        int go = q.front();
        q.pop();
        answer.push_back(go);
        for(int y : v[go]){
            visit[y]--;
            if(visit[y] == 0)
                q.push(y);
        }
    }
이 부분이 핵심! 사이즈가 안맞으면 잘못된것이므로 0을 출력
    if(answer.size() != n){
        cout << 0;
        return 0;
    }
    for(int y : answer)
        cout << y << "\n";
}