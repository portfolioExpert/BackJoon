//문제 1780번 종이의 개수 -> 분할정복
int map[2188][2188];
int result[3];
void fx(int n, int x, int y){
    if(n == 1){
        result[map[x][y] + 1]++;
        return;
    }
    bool minus = true;
    bool plus = true;
    bool zero = true;
    for(int i = x;i<x + n;i++){
        for(int j = y;j<y + n;j++){
            if(map[i][j] == -1){
                plus = false;
                zero = false;
            }
            else if(map[i][j] == 0){
                plus = false;
                minus = false;
            }
            else{
                minus = false;
                zero = false;
            }
        }
    }
    //종이의 개수를 새어 주는 것
    if(minus)
        result[0]++;
    else if(plus)
        result[2]++;
    else if(zero)
        result[1]++;
    //분할정복 부분
    else{
        //첫째 행
        fx(n/3, x, y);
        fx(n/3, x, y + n/3);
        fx(n/3, x, y + n/3 * 2);

        //둘째 행
        fx(n/3, x + n/3, y);
        fx(n/3, x + n/3, y + n/3);
        fx(n/3, x + n/3, y + n/3 * 2);

        //세번째 행
        fx(n/3, x + n/3 * 2, y);
        fx(n/3, x + n/3 * 2 , y + n/3);
        fx(n/3, x + n/3 * 2, y + n/3 * 2);
    }
    return;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    fx(n, 0, 0);
    for(int i = 0;i<3;i++){
        cout << result[i] << "\n";
    }
    return 0;
}