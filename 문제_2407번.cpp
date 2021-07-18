//문제 2407 조합 ->dp와 큰수의 덧셈
#include<string>
string dp[101][101];
string bigadd(string num1 ,string num2){
    string result = "";
    long long sum = 0;
    //num1나 num2가 비어있지 않고 sum 즉 캐리가 있을때 까지 돌아간다
    while(!num1.empty() || !num2.empty() || sum){
        //sum에 한자리씩 더한다
        if(!num1.empty()){
            sum+=num1.back() - '0';
            num1.pop_back();
        }
        if(!num2.empty()){
            sum+=num2.back() - '0';
            num2.pop_back();
        }
        //1의 자리를 문자열에 넣어주고
        result.push_back(sum % 10 + '0');
        //남은 캐리가 있을수 있으니 10으로 나누어 준다
        sum/=10;
    }
    //1의 자리부터 계산하여 다시 원래대로 뒤집어 준다
    reverse(result.begin(), result.end());
    return result;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n ,m;
    cin >> n >> m;
    for(int i = 1;i<=100;i++){
        dp[i][0] = to_string(1);
        dp[i][1] = to_string(i);
        dp[i][i] = to_string(1);
    }
    for(int i = 2;i<=100;i++){
        for(int j = 1;j<=i;j++){
            if(i == 7 && j == 2)
                cout << dp[i][j];
            dp[i][j] = bigadd(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    cout << dp[n][m];
}