//문제 16918번 봄버맨 -> 구현
#include <vector>
char map[201][201];
int r, c, n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//폭탄 설치
vector<pair<int,int>> install(char ch){
    vector<pair<int,int>>result;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(map[i][j] == '.'){
                map[i][j] = ch;
                result.push_back({i, j});
            }
        }
    }
    return result;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> r >> c >> n;
    vector<pair<int,int>>first;
    vector<pair<int,int>>second;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j] == 'O'){
                map[i][j] = '1';
                first.push_back({i, j});
            }
        }
    }
    bool installflag = 1;
    bool boomflag = 0;
    for(int i = 2;i<=n;i++){
        //2로 나누어 떨어지면 설치
        if(i % 2 == 0){
            //설치
            //두번재 차례면
            if(installflag){
                second = install('2');
                installflag = 0;
            }
            else{
                first = install('1');
                installflag = 1;
            }
        }
        //나머지가 있다면 펑
        else{
            //첫 번째가 터질 차례
            if(!boomflag){
                for(int j = 0;j<(int)first.size();j++){
                    int gox = first[j].first;
                    int goy = first[j].second;
                    if(map[gox][goy] == '2' || map[gox][goy] == '.')
                        continue;
                    map[gox][goy] = '.';
                    for(int k = 0; k<4;k++){
                        int gx = gox + dx[k];
                        int gy = goy + dy[k];
                        if(gx >= 0 && gx < r && gy >= 0 && gy < c && map[gx][gy] == '2'){
                            map[gx][gy] = '.';
                        }
                    }
                }
                boomflag = 1;
            }
            else{
                for(int j = 0;j<(int)second.size();j++){
                    int gox = second[j].first;
                    int goy = second[j].second;
                    if(map[gox][goy] == '1' || map[gox][goy] == '.')
                        continue;
                    map[gox][goy] = '.';
                    for(int k = 0; k<4;k++){
                        int gx = gox + dx[k];
                        int gy = goy + dy[k];
                        if(gx >= 0 && gx < r && gy >= 0 && gy < c && map[gx][gy] == '1'){
                            map[gx][gy] = '.';
                        }
                    }
                }
                boomflag = 0;
            }
        }
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(map[i][j] == '1' || map[i][j] == '2' || map[i][j] == 'O')
                cout << 'O';
            else
                cout << '.';
        }
        cout << "\n";
    }
}