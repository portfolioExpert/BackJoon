//문제 16198번 에너지 모으기 -> 백트래킹
#include <vector>
int result = 0, n;
void dfs(int index, int sum, vector<int>v, int cnt){
    if(cnt == n-2){
        result = max(result, sum);
        return;
    }
    for(int i = 1;i<(int)v.size() - 1;i++){
        int save = v[i];
        sum+=v[i-1] * v[i+1];
        v.erase(v.begin() + i);
        dfs(i + 1, sum, v, cnt + 1);
        v.insert(v.begin() + i, save);
        sum-=v[i-1] * v[i+1];
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    vector<int>v;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    for(int i = 1;i<n-1;i++){
        int save = v[i];
        int sum = v[i-1] * v[i+1];
        v.erase(v.begin() + i);
        dfs(i, sum, v, 1);
        v.insert(v.begin() + i, save);
    }
    cout << result;
}