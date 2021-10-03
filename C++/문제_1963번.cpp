//문제 1963번
#include <queue>
#include <cstring>
queue<int> q;
int dp[10001];
int check[10001];
int num[4] = {1000, 100, 10, 1};
bool fx(int x);
void bfs();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1000;i<10000;i++){
        if(fx(i) == true)
            check[i] = 1;
    }
    for(int i = 0;i<t;i++){
        memset(dp, -1, sizeof(dp));
        int num1, num2;
        cin >> num1 >> num2;
        q.push(num1);
        dp[num1] = 0;
        bfs();
        cout << dp[num2] << "\n";
    }
}
bool fx(int x){
    for(int i = 2; i * i <= x;i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
void bfs(){
    while(!q.empty()){
        int number = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            for(int j = 0;j<=9;j++){
                int go = number - ((number / num[i]) % 10) * num[i] + j * num[i];
                if(go >= 1000 && go < 10000 && dp[go] == -1 && check[go] == 1){
                    q.push(go);
                    dp[go] = dp[number] + 1;
                }
            }
        }
    }
}