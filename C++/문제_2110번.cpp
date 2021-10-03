//문제 2110번
//두 공유기 사이 최대 거리를 기준으로 이분탐색
int home[200001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, c;
    int left = 0, right, result = 0;
    cin >> n >> c;
    for(int i = 0;i<n;i++){
        cin >> home[i];
    }
    sort(home, home + n);
    right = home[n-1] - home[0];
    while(left<=right){
        int mid = (left + right) / 2;
        int start = home[0];
        int cnt = 1;
        for(int i = 1;i<n;i++){
//공유기 설치
            if(mid <= home[i] - start){
                cnt++;
                start = home[i];
            }
        }
//공유기 개수가 많을 때
        if(cnt>=c){
            result = mid;
            left = mid + 1;
        }
//공유기 개수가 적을 때
        else{
            right = mid - 1;
        }
    }
    cout << result;
}