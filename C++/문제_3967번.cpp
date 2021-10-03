#include <iostream>
#include <algorithm>
using namespace std;

//문제 3967번
#include <vector>
vector <pair<int,int>> v;
char map[5][9];
bool visit[13];
int total;
bool check();
void dfs(int index, int cnt);
int main(){
    int i, j;
    for(i=0;i<5;i++){
        for(j=0;j<9;j++){
            cin >> map[i][j];
            if(map[i][j] >= 'A' && map[i][j] <='L')
                visit[map[i][j] - 'A'] = 1;
            else if(map[i][j] == 'x'){
                v.push_back({i, j});
                total++;
            }
        }
    }
    dfs(0, 0);
    return 0;
}
bool check(){//6개의 줄에서 합이 26이 되는지 체크
       if ((map[0][4] - 'A' + 1) + (map[1][3] - 'A' + 1) + (map[2][2] - 'A' + 1) + (map[3][1] - 'A' + 1) != 26) return false;
       if ((map[0][4] - 'A' + 1) + (map[1][5] - 'A' + 1) + (map[2][6] - 'A' + 1) + (map[3][7] - 'A' + 1) != 26) return false;
       if ((map[1][1] - 'A' + 1) + (map[1][3] - 'A' + 1) + (map[1][5] - 'A' + 1) + (map[1][7] - 'A' + 1) != 26) return false;
       if ((map[3][1] - 'A' + 1) + (map[3][3] - 'A' + 1) + (map[3][5] - 'A' + 1) + (map[3][7] - 'A' + 1) != 26) return false;
       if ((map[4][4] - 'A' + 1) + (map[3][3] - 'A' + 1) + (map[2][2] - 'A' + 1) + (map[1][1] - 'A' + 1) != 26) return false;
       if ((map[4][4] - 'A' + 1) + (map[3][5] - 'A' + 1) + (map[2][6] - 'A' + 1) + (map[1][7] - 'A' + 1) != 26) return false;
       return true;
}

void dfs(int index, int cnt){//dfs로 전부 탐색
    int i, j;
    if(total == cnt){
        if(check()){
            for(i=0;i<5;i++){
                for(j=0;j<9;j++){
                    cout << map[i][j];
                }
                cout << "\n";
            }
            exit(0);
        }
        return;
    }
    for(i = 0; i<12;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            map[v[index].first][v[index].second] = i + 'A';
            dfs(index+1, cnt + 1);
            map[v[index].first][v[index].second] = 'x';//원상복귀
            visit[i] = 0;
        }
    }
}