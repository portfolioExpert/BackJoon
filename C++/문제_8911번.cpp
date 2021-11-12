//문제 8911번 거북이 -> 구현
//북 동 남 서
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int di = 0;//처음 방향
        int x = 0, y = 0;//처음 위치
        int columnmin = 0, columnmax = 0, rowmin = 0, rowmax = 0;
        string command;
        cin >> command;
        for(int j = 0;j<(int)command.size();j++){
            switch(command[j]){
                case 'F':
                    x += dx[di];
                    y += dy[di];
                    break;
                case 'B' :
                    x -= dx[di];
                    y -= dy[di];
                    break;
                case 'L':
                    di = (di + 3) % 4;
                    break;
                case 'R':
                    di = (di + 1) % 4;
                    break;
                default:
                    break;
            }
            columnmin = min(columnmin, y);
            columnmax = max(columnmax, y);
            rowmin = min(rowmin, x);
            rowmax = max(rowmax, x);
        }
        cout << (rowmax - rowmin) * (columnmax - columnmin) << "\n";
    }
}