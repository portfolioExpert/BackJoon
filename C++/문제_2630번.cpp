//문제 2630 색종이 만들기 -> 분할정복 기본
int n;
int map[129][129];
int paper, notpaper;
void fx(int n, int x, int y){
    if(x == n-1 && y == n-1){
        if(map[n-1][n-1] == 1)
            paper++;
        else
            notpaper++;
        return;
    }
    int num = map[x][y];
    bool flag = true;
    for(int i = x;i<x+n;i++){
        for(int j = y;j<y + n;j++){
            if(num != map[i][j]){
                flag = false;
                break;
            }
        }
        if(!flag)
            break;
    }
    if(flag){
        if(num)
            paper++;
        else
            notpaper++;
    }
    else{
        fx(n/2, x,y);
        fx(n/2, x+n/2, y);
        fx(n/2 , x, y+n/2);
        fx(n/2, x+n/2, y+n/2);
    }
    return;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    fx(n, 0, 0);
    cout << notpaper << "\n" << paper;
}