//문제 1072 게임 -> 이분 탐색
typedef long long ll;
int main(){
    ll x, y;
    cin >> x >> y;
    ll z = y * 100 / x;
    ll left = 0;
    ll right = 1e9;
    ll result = -1;
    if(z >= 99){
        cout << -1;
        return 0;
    }
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        ll total = x + mid;
        ll win = (y + mid) * 100;
        if(win / total <= 100 && (win / total - z)>= 1){
            result = mid;
            right = mid;
        }
        else
            left = mid;
    }
    cout << result;
}