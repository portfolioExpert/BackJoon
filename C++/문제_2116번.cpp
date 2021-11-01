//문제 2116 주사위 쌓기 -> 브루트포스
int dice[10001][7];
int against[7] = {0, 6, 4, 5, 2, 3, 1};
//6부터 최댓값을 리턴하는 것
int maxval(int first, int second){
    for(int i = 6;i>=1;i--){
        if(i != first && i != second)
            return i;
    }
    return 6;
}
//n번째 주사위 값의 인덱스를 찾는 것
int searchIndex(int n, int num){
    for(int i = 1;i<=6;i++){
        if(dice[n][i] == num)
            return i;
    }
    return 0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    int result = 0;
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=6;j++){
            cin >> dice[i][j];
        }
    }
    //1번 주사위 바닥에 따라 최대값이 달라진다.
    //바닥을 1번부터 6번인덱스를 깔고 본다.
    for(int i = 1;i<=6;i++){
        int sum = 0;
        int top = dice[1][i];
        sum+=maxval(dice[1][against[i]], top);
        for(int j = 2;j<=n;j++){
            //top의 값이랑 같은 값을 찾아 인덱스에 넣어준다.
            int bottom = top;
            top = dice[j][against[(searchIndex(j, top))]];
            sum+=maxval(bottom, top);
        }
        result = max(result, sum);
    }
    cout << result;
}