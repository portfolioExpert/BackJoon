//문제 1038번
typedef long long ll;
#include <string>
#include <vector>
string str = "";
vector<ll>v;
void dfs(int val);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<=9;i++){
        v.push_back(i);
    }
    for(int i = 9;i>=1;i--){
        str+=to_string(i);
        dfs(i);
        str = str.substr(0, str.size() - 1);
    }
    sort(v.begin(), v.end());
    if(v.size() - 1 < n)
        cout << -1;
    else
        cout << v[n];
}
void dfs(int val){
    if(val<=0){
        return;
    }
    for(int i = val - 1;i>=0;i--){
        str+=to_string(i);
        v.push_back(stoll(str));
        dfs(i);
        str = str.substr(0, str.size() - 1);
    }
}