//문제 17144번
#include <vector>
#include <cstring>
vector<pair<int ,int>> machine;
int map[51][51];
int after[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c, t;
int upx, upy, downx, downy;
void move();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> r >> c >> t;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j] == -1){
                machine.push_back({i, j});
            }
        }
    }
    while(t--){
        memset(after, 0 , sizeof(after));
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                int val = map[i][j] / 5;
                if(map[i][j]>=0){
                    int cnt = 0;
                    for(int k = 0;k<4;k++){
                        int gx = i + dx[k];
                        int gy = j + dy[k];
                        if(gx>=0 && gx < r && gy >= 0 && gy < c && map[gx][gy] != -1){
                            after[gx][gy] += val;
                            cnt++;
                        }
                    }
                    map[i][j] = map[i][j] - cnt * val;
                }
            }
        }
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                map[i][j]+=after[i][j];
            }
        }
        move();
//        cout <<"\n";
//        for(int i = 0;i<r;i++){
//            for(int j = 0;j<c;j++){
//                cout << map[i][j] << " ";
//            }
//            cout << "\n";
//        }
    }
    int result = 0;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(map[i][j] >= 1)
                result+=map[i][j];
        }
    }
    cout << result;
}
void move(){
    int save1, save2, i, j;
    int upx, upy, downx, downy;
    upx = machine[0].first;
    upy = machine[0].second;
    save1 = map[upx][c-1];
    for(j = c - 1;j>upy+1; j--){
        map[upx][j] = map[upx][j-1];
    }
    //이것때문..
//    map[upx][upy+1] = map[upx-1][upy];//오른쪽으로 옮기기
    map[upx][upy+1] = 0;

    save2 = map[0][c-1];//맨위 맨오른쪽 값 저장
    for(i = 0; i<upx - 1; i++){
        map[i][c-1] = map[i+1][c-1];
    }
    map[i][c-1] = save1;

    save1 = map[0][0];
    for(j = 0;j<c-2;j++){
        map[0][j] = map[0][j+1];
    }
    map[0][j] = save2;

    for(i = upx - 1;i>1;i--){
        map[i][0] = map[i-1][0];
    }
    map[i][0] = save1;

    downx = machine[1].first;
    downy = machine[1].second;

    save1 = map[downx][c-1];
    for(j = c-1; j > downy + 1;j--){
        map[downx][j] = map[downx][j-1];
    }
    //이것때문..
//    map[downx][downy+1] = map[downx+1][downy];
    map[downx][downy+1] = 0;

    save2 = map[r-1][c-1];
    for(i = r-1;i>downx + 1;i--){
        map[i][c-1] = map[i-1][c-1];
    }
    map[downx + 1][c-1] = save1;

    save1 = map[r-1][0];
    for(j = 0;j<c-1;j++){
        map[r-1][j] = map[r-1][j+1];
    }
    map[r-1][c-2] = save2;

    for(i = downx + 1; i < r-1;i++){
        map[i][0] = map[i+1][0];
    }
    map[r-2][0] = save1;
}