//문제 1365번 꼬인 전깃줄 -> nlogn 가장 긴 증가하는 부분수열
int num[100001];
int len;
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
    cout << n - len;
}