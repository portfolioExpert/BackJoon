#include <iostream>
#include <algorithm>
using namespace std;

//문제14501번
#include <vector>
vector<pair<int,int>> v;
int n, result = 0, sum;
int p[16], t[16];
void dfs(int index);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i;
    cin >> n;
    for(i = 1;i<=n;i++){
        cin >> t[i] >> p[i];
    }
    for(i = 1;i<=n;i++){
        if(t[i] + i <= n + 1){
            sum = p[i];
            result = max(result, sum);
            dfs(t[i] + i);
        }
    }
    cout << result;
}
void dfs(int index){
    if(index > n)
        return;
    for(int i = index;i<=n;i++){
        if(i + t[i] <= n + 1){
            sum+=p[i];
            result = max(result, sum);
            dfs(i + t[i]);
            sum-=p[i];
        }
    }
}