//문제 4796번 캠핑 -> 수학
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int l, p, v;
    for(int i = 1;;i++){
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0)
            break;
        int answer = 0;
        answer += v / p * l;
        if(v % p > l)
            v = l;
        v%=p;
        answer+=v;
        cout << "Case " << i << ": " << answer << "\n";
    }
}