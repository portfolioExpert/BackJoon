//문제 9184번 신나는 함수 실행 -> DP, 재귀
#include<cstring>
int dp[51][51][51];
int w(int a, int b ,int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if(dp[a][b][c] != -1)
        return dp[a][b][c];
    if(a < b && b < c)
        return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1){
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << "\n";
    }
}