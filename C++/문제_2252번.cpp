//문제 2252번 줄 세우기 ->위상정렬 기본
#include <vector>
#include<queue>
queue<int>q;
vector<int>v[32001];
int visit[32001];
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
            q.push(i);
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
    for(int y : answer)
        cout << y << " ";
}