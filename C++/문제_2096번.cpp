//문제 2096번 특이한 dp 받는 족족 바로 처리해야한다.
int maxval = -1, minval = 1111111111;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    int b1, b2, b3, b4, b5, b6;
    cin >> b1 >> b2 >> b3;
    maxval = max(b1, max(b2, b3));
    b4 = b1;
    b5 = b2;
    b6 = b3;
    minval = min(b4, min(b5, b6));
    for(int i = 1;i<n;i++){
        int num1 ,num2, num3;
        cin >> num1 >> num2 >> num3;
        int save1 = max(b1, b2) + num1;
        int save2 = max(b1, max(b2, b3)) + num2;
        int save3 = max(b2, b3) + num3;
        b1 = save1;
        b2 = save2;
        b3 = save3;
        maxval = max(b1, max(b2, b3));

        int save4 = min(b4, b5) + num1;
        int save5 = min(b4, min(b5, b6)) + num2;
        int save6 = min(b5, b6) + num3;
        b4 = save4;
        b5 = save5;
        b6 = save6;
        minval = min(b4, min(b5, b6));
    }
    cout << maxval << " " << minval;
}