#include <iostream>
#include <algorithm>
using namespace std;

//문제 1051번 숫자 정사각형 -> 브루트포스
#include <vector>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    //원점, 아래, 왼쪽, 대각
    int dx[4] = {0, 1, 0, 1};
    int dy[4] = {0, 0, 1, 1};
    cin >> n >> m;
    char map[51][51];
    int result = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char number = map[i][j];
            vector<pair<int,int>>v;
            v.push_back({i, j});
            v.push_back({i, j});
            v.push_back({i, j});
            v.push_back({i, j});
            bool flag = true;
            while(1){
                if(!flag)
                    break;
                //한번씩 더하고
                for(int k = 0;k<4;k++){
                    v[k].first += dx[k];
                    v[k].second += dy[k];
                    //범위를 넘어가면
                    if(v[k].first < 0 || v[k].first >= n || v[k].second < 0 || v[k].second >= m){
                        flag = false;
                        break;
                    }
                }
                //체크하고
                bool eq = true;
                for(auto y : v){
                    if(map[y.first][y.second] != number){
                        eq = false;
                        break;
                    }
                }
                if(eq){
                    result = max(result, (v[3].first - i + 1) * (v[3].second - j + 1));
                }
            }
        }
    }
    cout << result;
}