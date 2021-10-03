#include <iostream>
#include <algorithm>
using namespace std;

//문제 2668 사이클 찾아서 사이클이 있는 번호 추가
#include <vector>
vector<int> v[101];
vector<int> ans;
int result, start;
bool visit[101];
void dfs(int x);
int main(){
    int n, i, num;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> num;
        v[i].push_back(num);
    }
    for(i=1;i<=n;i++){
        start = i;
        dfs(i);
        fill_n(visit, 101, 0);
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
void dfs(int x){
    if(visit[x] == 1){
        if(x == start){
            ans.push_back(x);
        }
    }
    else{
        visit[x] = 1;
        dfs(v[x][0]);
    }
}