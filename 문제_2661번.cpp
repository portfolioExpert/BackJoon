//문제 2661번 문자열 백트래킹
#include <string>
string str = "";
int n;
void dfs(int cnt);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i<=3;i++){
        dfs(i);
    }
}
void dfs(int cnt){
    if(str.size() == n || cnt == n){
        cout << str;
        exit(0);
    }
    str+=to_string(cnt);
    for(int i = (int)str.size() - 1;i>=str.size() / 2;i--){
        string right = str.substr(i);
        if(i - (int)right.size() < 0)break;
        string left = str.substr(i - right.size(), right.size());
        if(left == right){
            str = str.substr(0, str.size() - 1);
            return;
        }
    }
    for(int i = 1;i<=3;i++){
        dfs(i);
    }
    str = str.substr(0, str.size() - 1);
}