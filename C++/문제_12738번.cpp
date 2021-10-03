//문제 12738번 가장 긴 증가하는 부분 수열 3 -> nlogn 가장 긴 증가하는 부분수열
typedef long long ll;
ll num[1000001];
ll len;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int number;
        cin >> number;
        auto pos = lower_bound(num+1, num + len + 1, number);
        *pos = number;
        if(pos == num + len + 1)
            len++;
    }
    cout << len;
}