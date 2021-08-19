//문제 14650번 걷다보니 신천역 삼(Small) -> 백트래킹
int n;
long long sum = 0;
int cnt = 0;
void dfs(int index){
    if(index == n){
        if(sum % 3 == 0)
            cnt++;
        return;
    }
    for(int i = 0;i<=2;i++){
        sum*=10;
        sum+=i;
        dfs(index + 1);
        sum-=i;
        sum/=10;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 1;i<=2;i++){
        sum+=i;
        dfs(1);
        sum-=i;
    }
    cout << cnt;
}