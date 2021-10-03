//문제 1062번
#include <string>
string str[51];
int visit[26];
int n , k, result = 0;
void dfs(int now, int cnt);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> k;
    if(k < 5){
        cout << 0;
        return 0;
    }
    visit['a' - 'a'] = 1;
    visit['n' - 'a'] = 1;
    visit['t' - 'a'] = 1;
    visit['i' - 'a'] = 1;
    visit['c' - 'a'] = 1;
    k-= 5;

    for(int i = 0;i<n;i++){
        cin >> str[i];
        str[i] = str[i].substr(4);
        str[i] = str[i].substr(0, str[i].size() - 4);
    }
    for(int i = 0;i<n;i++){
        bool flag = 1;
        for(int j = 0;j<str[i].size();j++){
            if(visit[str[i][j] - 'a'] == 0){
                flag = 0;
                break;
            }
        }
        if(flag)
            result++;
    }
    for(int i = 0;i<26;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            dfs(i, 1);
            visit[i] = 0;
        }
    }
    cout << result;
}
void dfs(int now, int cnt){
    if(cnt == k){
        int sum = 0;
        for(int i = 0;i<n;i++){
            bool flag = 1;
            for(int j = 0;j<str[i].size();j++){
                if(visit[str[i][j] - 'a'] == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                sum++;
        }
        result = max(result, sum);
        return;
    }
    for(int i = now + 1;i<26;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            dfs(i, cnt + 1);
            visit[i] = 0;
        }
    }
}