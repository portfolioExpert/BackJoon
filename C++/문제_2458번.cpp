//문제 2458번 키순서 -> dfs 탐색 문제
#include <vector>
#include <cstring>
vector<int>v[501];
bool visit[501];
bool save[501][501];//키정보를 아는지 체크
void dfs(int go, int start){
    visit[go] = 1;
    for(int y : v[go]){
        if(visit[y] == 0){
            //키정보 체크 후 dfs 탐색
            save[go][y] = 1;
            save[y][go] = 1;
            save[y][start] = 1;
            save[start][y] = 1;
            dfs(y, start);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int result = 0;
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
    }
    for(int i = 1;i<=n;i++){
        memset(visit, 0, sizeof(visit));
        dfs(i, i);
    }
    for(int i = 1;i<=n;i++){
        int j = 1;
        for(;j<=n;j++){
            if(save[i][j] == 0 && i != j)
                break;
        }
        if(j > n)
            result++;
    }
    cout << result;
}