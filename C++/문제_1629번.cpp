//문제 1629번 곱셈 -> 분할정복을 이용한 거듭제곱
typedef long long ll;
ll fx(int a, int b, int c){
    if(b == 1)
        return a;
    else{
        //10 ^ 10 = (10 ^ 5) ^ 2 를 이용한다
        //그렇게 해주기 위해서 b/2를 계속 나누어 주고
        //나머지 짝수 홀수에 따라서 결정해준다
        ll value = fx(a, b / 2, c);
        if(b % 2)
            return ((value * value) % c * a) % c;
        else
            return (value * value) % c;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    cout << fx(a % c, b, c);
}