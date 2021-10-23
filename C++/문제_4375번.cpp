//문제 4375 1 -> 수학
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    while(cin >> n){
        int num = 0;
        for(int i = 1;i<=n;i++){
            num = num * 10 + 1;
            num %= n;
            if(num == 0){
                cout << i << "\n";
                break;
            }
        }
    }
}