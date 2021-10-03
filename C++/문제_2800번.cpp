//문제 2800번 괄호제거 -> 스택, 백트래킹
#include <string>
#include <vector>
#include <stack>
#include <string.h>
stack<int>s;
vector<string>result;
vector<pair<int,int>>in;
int n,leng;
string makestr(char ch[]){
    string result = "";
    for(int i = 0;i<leng;i++){
        if(ch[i] != '\0'){
            result+=ch[i];
        }
    }
    return result;
}
void dfs(char ch[], int index){
    if(index == n){
        return;
    }
    for(int i = index + 1;i<n;i++){
        ch[in[i].first] = '\0';
        ch[in[i].second] = '\0';
        result.push_back(makestr(ch));
        dfs(ch, i);
        ch[in[i].first] = '(';
        ch[in[i].second] = ')';
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    char str[220];
    cin >> str;
    leng = (int)strlen(str);
    for(int i = 0;i<(int)strlen(str);i++){
        if(str[i] == '(' || str[i] == ')'){
            if(str[i] == '('){
                s.push(i);
                n++;
            }
            else{
                in.push_back({s.top(),i});
                s.pop();
            }
        }
    }
    for(int i = 0;i<n;i++){
        str[in[i].first] = '\0';
        str[in[i].second] = '\0';
        result.push_back(makestr(str));
        dfs(str, i);
        str[in[i].first] = '(';
        str[in[i].second] = ')';
    }
    //벡터에서 중복값을 제거해 주기 위해서는 정렬해야한다.
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    for(int i = 0;i<(int)result.size();i++){
        cout << result[i] << "\n";
    }
}