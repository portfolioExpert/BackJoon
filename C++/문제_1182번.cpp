//문제 1182번 부분수열의 합
int sum = 0;
int result;
void dfs(int index);
int num[21];
int visit[21];
int n, s;
bool flag = 0;
bool check(){
    for(int i = 0;i<n;i++){
        if(visit[i] == 1)
            return true;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> s;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    dfs(0);
    cout << result;
}
void dfs(int index){
    if(sum == s && check()){
        result++;
    }
    if(index == n)
        return;
    for(int i = index;i<n;i++){
        if(visit[i] == 0){
            sum+=num[i];
            visit[i] = 1;
            dfs(i + 1);
            sum-=num[i];
            visit[i] = 0;
        }
    }
}