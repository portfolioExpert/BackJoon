#include <iostream>
#include <algorithm>
using namespace std;

//문제 1043번
#include <queue>
#include <vector>
queue <int> q;
bool visit[51];
int num[51][51];
vector <int> v[51];
void dfs(int x);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, i, tr, input, result = 0, cnt[51], j;
    cin >> n >> m;
    cin >>tr;
    for(i=0;i<tr;i++){
        cin >> input;
        q.push(input);//숙주를 큐에 넣고
    }
    for(i=0;i<m;i++){
        cin >> cnt[i];
        for(j = 0;j<cnt[i]; j++){
            cin >> num[i][j];//테케마다 다른 t배열에 정수들을 받는다
            if(num[i][0] != num[i][j]){
                v[num[i][0]].push_back(num[i][j]);//벡터로 연결해주고
                v[num[i][j]].push_back(num[i][0]);
            }
        }
    }
    if(tr == 0){
        cout << m;
    }
    else{
        while(!q.empty()){//하나씩 꺼내서 dfs를 돌려 주변 노드를 감염시킴 이후 visit 배열이 완성되고
            dfs(q.front());
            q.pop();
        }
        for(i=0;i<m;i++){//테스트 케이스의 값을 검사하여 visit가 되었는지 살핀다
            for(j=0;j<cnt[i];j++){
                if(visit[num[i][j]] == 1)
                    break;
            }
            if(j == cnt[i])result++;
        }
        cout << result;
    }
    return 0;
}
void dfs(int x){
    visit[x] = 1;
    for(int y : v[x]){
        if(visit[y] == 0){
            visit[y] = 1;
            dfs(y);
        }
    }
}a