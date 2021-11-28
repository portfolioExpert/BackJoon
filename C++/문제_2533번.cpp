//문제 2533번 사회망 서비스(SNS) -> 트리 DP
#include <vector>
#include <cstring>
vector<int>v[1000001];
vector<int>tree[1000001];
int dp[1000001][2];
void makeTree(int root, int parent){
    if(parent != 0)tree[parent].push_back(root);
    for(int y : v[root]){
        if(y == parent)
            continue;
        makeTree(y, root);
    }
}
int dfs(int go, bool flag){
    int &ret = dp[go][flag];
    if(ret != -1)
        return ret;
    if(flag)
        ret = 1;
    else
        ret = 0;
    for(int i = 0;i<tree[go].size();i++){
        //부모가 0이므로 자식은 1
        if(flag == 0)
            ret += dfs(tree[go][i], 1);
        //부모가 1 이면 자식은 0 이거나 1
        else{
            ret += min(dfs(tree[go][i], 0), dfs(tree[go][i], 1));
        }
    }
    return ret;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n - 1;i++){
        int num1, num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    memset(dp, -1, sizeof(dp));
    makeTree(1, 0);
    cout << min(dfs(1, 0), dfs(1, 1));
}