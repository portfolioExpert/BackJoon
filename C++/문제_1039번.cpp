//문제 1039번 교환 -> dfs
int result = -1;
bool visit[11][1000001];
int len, k;
string str;
string swapping(int i, int j, string str){
    string res = str;
    char save = res[i];
    res[i] = res[j];
    res[j] = save;
    return res;
}
void dfs(int cnt, string num, int index){
    //종료 조건
    if(cnt == k){
        result = max(result, stoi(num));
        return;
    }
    for(int i = 0;i<str.size();i++){
        for(int j = i + 1;j<str.size();j++){
            string next = swapping(i, j, num);
            if(next[0] == '0')
                continue;
            if(visit[cnt][stoi(next)] == 0){
                visit[cnt][stoi(next)] = 1;
                dfs(cnt + 1, next, i + 1);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> str >> k;
    dfs(0, str, 0);
    cout << result;
}