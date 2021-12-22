//문제 1091번 카드 섞기 -> 시뮬레이션
//이문제는 왜 100만을 최대로 섞는 회수로 잡아야하는가?
int p[49];
int s[49];
int before[49];//i번은 before[i]번 플레이어 것
int after[49];//i번은 after[i]번 플레이어 것
int goal[49]; //i번은 goal[i]번 플레이어 것이다
int n;
//0 1 2 0 1 2로 가야한다
bool ch(){
    for(int i = 0;i<n;i++){
        if(before[i] != i % 3)
            return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    int result = 0;
    for(int i = 0;i<n;i++){
        cin >> p[i];
        before[i] = p[i];
    }
    for(int i = 0;i<n;i++){
        cin >> s[i];
    }
    for(int i = 0;i<1000000;i++){
        //같을 경우
        if(ch())
            break;
        else{
            //변환
            for(int j = 0;j<n;j++){
                after[s[j]] = before[j];
            }
            for(int j = 0;j<n;j++){
                before[j] = after[j];
            }
        }
        result++;
    }
    if(result == 1000000)
        cout << -1;
    else
        cout << result;
}