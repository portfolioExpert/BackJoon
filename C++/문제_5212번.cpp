//문제 5212번 지구 온난화 -> 구현
#include <vector>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[11][11];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int r, c;
    cin >> r >> c;
    int minx = 987654321;
    int miny = 987654321;
    int maxx = 0;
    int maxy = 0;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
        }
    }
    vector<pair<int,int>>v;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(map[i][j] == 'X'){
                int cnt = 0;
                for(int k = 0;k<4;k++){
                    int gox = i + dx[k];
                    int goy = j + dy[k];
                    if(gox < 0 || gox >= r || goy < 0 || goy >= c || map[gox][goy] == '.')
                        cnt++;
                }
                if(cnt < 3){
                    maxx = max(maxx, i);
                    maxy = max(maxy, j);
                    v.push_back({i, j});
                    minx = min(minx, i);
                    miny = min(miny, j);
                }
            }
        }
    }
    sort(v.begin(), v.end());
    int index = 0;
    for(int i = minx;i<=maxx;i++){
        for(int j = miny;j<=maxy;j++){
            if(index < v.size() && i == v[index].first && j == v[index].second){
                cout << "X";
                index++;
            }
            else
                cout << ".";
        }
        cout << "\n";
    }
}