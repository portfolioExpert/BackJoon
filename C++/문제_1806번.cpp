//문제 1806번 부분합 -> 투 포인터
int number[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    for(int i = 0;i<n;i++){
        cin >> number[i];
    }
    int sum = 0;
    int length = 987654321;
    int left = 0, right = 0;
    while(left <= right){
        //while안에 right < n 을 넣으면 끝값을 찾았을때 조건문이 안먹어서
        //5 5
        //1 1 1 1 1 반례에 걸림
        if(sum < s){
            if(right == n)break;
            sum+=number[right];
            right++;
        }
        else{
            sum-=number[left];
            length = min(length, right - left);
            left++;
        }
    }
    if(length == 987654321)
        cout << 0;
    else
        cout << length;
}