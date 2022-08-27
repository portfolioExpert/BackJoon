//문제 16987번 계란으로 계란치기 -> 백트래킹
#include <vector>
vector<pair<int,int>>v;
bool visit[9];
int result = 0;
int n;
void dfs(int index){
    if(index >= n){
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(v[i].first <= 0)
                sum++;
        }
        result = max(result, sum);
        return;
    }
    //집어든 계란이 깨졌다면 다음 계단 들고
    if(v[index].first <= 0)
        dfs(index + 1);
    //안깨졌다면
    else{
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(i == index || v[i].first < 0)
                continue;
            v[i].first -= v[index].second;
            v[index].first -= v[i].second;
            flag = true;
            dfs(index + 1);
            v[i].first+= v[index].second;
            v[index].first+= v[i].second;
        }
        //더 이상 깰 계란이 없다면 개수를 세준다
        if(!flag)dfs(n);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        int state, weight;
        cin >> state >> weight;
        v.push_back({state, weight});
    }
    dfs(0);
    cout << result;
}