//문제 2003번 수들의 합2 -> 투 포인터
int arr[10001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int left = 0, right = 0, result = 0, sum =0;
    while(1){
        if(sum >= m)sum-=arr[left++];
        else if(right == n)break;
        else
            sum+=arr[right++];
        if(sum == m)result++;
    }
    cout << result;
}