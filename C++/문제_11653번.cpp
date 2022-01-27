//문제 11653번 소인수 분해 -> 소수판정, 구현
bool fx(int n){
    for(int i = 2;i * i<=n;i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n > 1){
        for(int i = 2;i<=10000000;i++){
            if(n % i == 0 && fx(i)){
                cout << i << "\n";
                n/=i;
                break;
            }
        }
    }
}