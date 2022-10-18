//문제 1138번 한 줄로 서기 -> 백트래킹, 브루트포스
#include <vector>
int n;
bool visit[11];
int arr[11]; //인덱스는 키, 값은 왼쪽의 갯수
vector<int>v;//키를 넣고 // 1 2 3 4
void dfs(int cnt){
    if(cnt == n){
        for(int i = 0;i<v.size();i++){
            int cnt = 0;
            for(int j = 0;j<i;j++){
                if(v[j] > v[i])
                    cnt++;
            }
            if(cnt != arr[v[i]])
                return;
        }
        for(int i = 0;i<v.size();i++){
            cout << v[i] << " ";
        }
        exit(0);
    }
    for(int i = 1;i<=10;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            v.push_back(i);
            dfs(cnt + 1);
            v.pop_back();
            visit[i] = 0;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    dfs(0);
}