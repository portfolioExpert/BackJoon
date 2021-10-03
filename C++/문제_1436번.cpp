//문제 1436번 영화감독 숌 -> 브루트포스
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, n, cnt = 0;
    cin >> n;
    for(i = 666;cnt < n;i++){
        int go = i;
        int sixcnt = 0;
        while(go){
            if(sixcnt == 3)
                break;
            if(go % 10 == 6)
                sixcnt++;
            else
                sixcnt = 0;
            go/=10;
        }
        if(sixcnt == 3)
            cnt++;
    }
    cout << i - 1;
}