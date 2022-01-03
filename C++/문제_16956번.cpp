//문제 16956번 늑대와 양 -> 구현
#include <vector>
#include <queue>
char map[501][501];
int n, m;
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1 ,0 ,-1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    bool flag = true;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(map[i][j] == 'W'){
                for(int k = 0;k<4;k++){
                    int gox = i + dx[k];
                    int goy = j + dy[k];
                    if(gox >= 0 && gox < n && goy >= 0 && goy < m){
                        if(map[gox][goy] == 'S'){
                            flag = 0;
                            cout << flag;
                            return 0;
                        }
                        else if(map[gox][goy] == '.')
                            map[gox][goy] = 'D';
                    }
                }
            }
        }
    }
    if(flag){
        cout << flag << "\n";
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout << map[i][j];
            }
            cout << "\n";
        }
    }
    else
        cout << flag;
}