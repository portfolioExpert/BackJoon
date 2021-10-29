//문제 15961번 회전 초밥 -> 투 포인터
int price[3000001];
int visit[3001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for(int i = 0;i<n;i++){
        cin >> price[i];
    }
    int left = 0, right = 0, cnt = 0, result = 0, type = 0;
    //cnt는 개수, type은 종류
    while(1){
        //횟수가 일치하다면 left 증가
        if(cnt >= k){
            //쿠폰을안먹었을때 추가로 제공
            if(visit[c] == 0)
                result = max(result, type + 1);
            else
                result = max(result, type);
            cnt--;
            //한 종류면
            if(visit[price[left]] == 1)
                type--;
            visit[price[left++]]--;
        }
        //종료 조건
        else if(left == n)
            break;
        else{
            //새로운 종류
            if(visit[price[right % n]] == 0)
                type++;
            //개수 증가
            cnt++;
            visit[price[(right++) % n]]++;
        }
    }
    cout << result;
}