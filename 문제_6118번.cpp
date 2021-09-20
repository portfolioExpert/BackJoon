//문제 6118번 숨바꼭질 -> BFS
#include <vector>
#include <queue>
#include <cstring>
queue<int>q;
vector<int>v[20001];
int visit[20001];
void bfs(){
    q.push(1);
    visit[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int y : v[now]){
            if(visit[y] == -1){
                visit[y] = visit[now] + 1;
                q.push(y);
            }
        }
    }
}
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
        v[num2].push_back(num1);
    }
    fill_n(visit, n+1 , -1);
    bfs();
    vector<int>result;
    int length = 0;
    for(int i = 1;i<=n;i++){
        if(length < visit[i]){
            result.clear();
            result.push_back(i);
            length = visit[i];
        }
        else if(length == visit[i])
            result.push_back(i);
    }
    sort(result.begin(),result.end());
    cout << result[0] << " "<< visit[result[0]] << " " << result.size();
}