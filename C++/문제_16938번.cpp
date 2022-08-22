//문제 16938번 캠프준비 -> 백트래킹
#include <vector>
int n, l, r, x;
int num[16];
int result;
void dfs(int index, vector<int>v){
    if(index == n){
        sort(v.begin(), v.end());
        if(v.size() == 0)
            return;
        if(v.back() - v.front() < x)
            return;
        int sum = 0;
        for(int y : v){
            sum+=y;
        }
        if(sum >= l && sum <= r){
            result++;
        }
        return;
    }
    v.push_back(num[index]);
    dfs(index+1, v);
    v.pop_back();
    dfs(index+1, v);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> l >> r >> x;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    vector<int>v;
    dfs(0, v);
    cout << result;
}