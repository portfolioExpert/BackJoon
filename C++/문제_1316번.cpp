//문제 1316번
#include <string>
#include <cstring>
int visit[26];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, i, j, result = 0;
    cin >> n;
    for(i = 0;i<n;i++){
        memset(visit, 0, sizeof(visit));
        string str;
        cin >> str;
        visit[str[0] - 'a'] = 1;
        for(j = 1;j<str.size();j++){
            if(str[j-1] == str[j])
                continue;
            if(visit[str[j] - 'a'] == 1)break;
            visit[str[j] - 'a'] = 1;
        }
        if(j == str.size())
            result++;
    }
    cout << result;
}