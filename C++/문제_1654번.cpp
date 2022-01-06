//문제 1654번 랜선 자르기 -> 이분 탐색
typedef long long ll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int k, n;
    ll rope[10001];
    ll result = 0;
    cin >> k >> n;
    for(int i = 0;i<k;i++){
        cin >> rope[i];
    }
    ll left = 0;
    ll right = 20000000000000;
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        int cnt = 0;
        for(int i = 0;i<k;i++){
            cnt+= rope[i] / mid;
        }
        if(cnt >= n){
            left = mid;
            result = max(result, left);
        }
        else if(cnt < n)
            right = mid;
    }
    cout << result;
}