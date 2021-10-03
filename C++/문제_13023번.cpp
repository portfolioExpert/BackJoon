//문제 13023번 ABCDE -> dfs, 방문했던 곳 재 방문 처리
#include <cstring>
#include <vector>
vector<int>v[2001];
bool visit[2001];
bool flag = 0;
void dfs(int go, int cnt){
    if(cnt > 3){
        flag = 1;
        return;
    }
    visit[go] = 1;
    for(int y : v[go]){
        if(visit[y] == 0){
            dfs(y, cnt + 1);
        }
        if(flag)
            return ;
    }
    //꼭 필요한 이유는 처음 방문 했던 길이 무조건 정답이 될 수 있는것은 아니라
    //다음에도 방문할 수 있도록 해줘야한다
    visit[go] = 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n , m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int num1 ,num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    for(int i = 0;i<n;i++){
        if(flag)
            break;
        memset(visit, 0, sizeof(visit));
        dfs(i, 0);
    }
    cout << flag;
}