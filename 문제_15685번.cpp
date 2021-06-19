//문제 15685번
#include <vector>
int map[101][101];
//동 북 서 남
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n, result;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        int y, x, d, g;
        cin >> y >> x >> d >> g;
        vector<int>cur;
        cur.push_back(d);//첫 방향을 저장하고
        for(int j = 0;j<g;j++){
            vector<int>getter = cur;//세대별로 저장한다
            for(int k = (int)cur.size() - 1;k>=0;k--){
                cur.push_back((getter[k] + 1) % 4);//다음 세대 방향을 전의 세대에서 90도 회전시켜서 방향을 저장해준다
            }
        }
        //그린다
        map[x][y] = 1;
        for(int j = 0;j<cur.size();j++){
            x += dx[cur[j]];
            y += dy[cur[j]];
            if(x >= 0 && x <= 100 && y >= 0 && y <= 100)
                map[x][y] = 1;
        }
    }
    for(int i = 0;i<100;i++){
        for(int j = 0;j<100;j++){
            if(map[i][j] == 1 && map[i+1][j] == 1 && map[i][j+1] == 1 && map[i+1][j+1] == 1)
                result++;
        }
    }
    cout << result;
}