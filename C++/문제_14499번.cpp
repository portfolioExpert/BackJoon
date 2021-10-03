//문제 14499번 빡 구현
int map[21][21];
int n, m ,k, x ,y;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
//위쪽 정면 아래 후면 왼쪽 오른쪽
int state[6];
void move(int comm);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m >> x >> y >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<k;i++){
        int comm;
        cin >> comm;
        move(comm);
    }
}
void move(int comm){
    if(comm == 1 && y + 1 < m){
        y = y+1;
        int save = state[5];
        state[5] = state[0];
        state[0] = state[4];
        state[4] = state[2];
        state[2] = save;
        if(map[x][y] == 0){
            map[x][y] = state[2];
        }
        else{
            state[2] = map[x][y];
            map[x][y] = 0;
        }
        cout << state[0] << "\n";
    }
    else if(comm == 2 && y - 1 >= 0){
        y = y-1;
        int save = state[0];
        state[0] = state[5];
        state[5] = state[2];
        state[2] = state[4];
        state[4] = save;
        if(map[x][y] == 0){
            map[x][y] = state[2];
        }
        else{
            state[2] = map[x][y];
            map[x][y] = 0;
        }
        cout << state[0] << "\n";
    }
    else if(comm == 3 && x - 1 >= 0){
        x = x-1;
        int save = state[0];
        state[0] = state[1];
        state[1] = state[2];
        state[2] = state[3];
        state[3] = save;
        if(map[x][y] == 0){
            map[x][y] = state[2];
        }
        else{
            state[2] = map[x][y];
            map[x][y] = 0;
        }
        cout << state[0] << "\n";
    }
    else if(comm == 4 && x + 1 < n){
        x = x+1;
        int save = state[0];
        state[0] = state[3];
        state[3] = state[2];
        state[2] = state[1];
        state[1] = save;
        if(map[x][y] == 0){
            map[x][y] = state[2];
        }
        else{
            state[2] = map[x][y];
            map[x][y] = 0;
        }
        cout << state[0] << "\n";
    }
}