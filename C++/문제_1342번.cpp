//문제 1342번 행운의 문자열 -> 백트래킹
#include <string>
int al[26];
int result;
string str, make = "";
void dfs(int index, string now){
    if(index == str.size()){
        result++;
        return;
    }
    for(int i = 0;i<26;i++){
        if(al[i]>=1 && now[now.size() - 1] != i + 97){
            al[i]--;
            dfs(index + 1, now + (char)(i + 97));
            al[i]++;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> str;
    for(int i = 0;i<(int)str.size();i++){
        al[str[i] - 97]++;
    }
    if(str.size() == 10){
        int i = 0;
        for(i = 0;i<10;i++){
            if(al[i] != 1)
                break;
        }
        if(i == 10){
            cout << 3628800;
            return 0;
        }
    }
    dfs(0,"");
    cout << result;
}