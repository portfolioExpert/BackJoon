#include <iostream>
#include <algorithm>
using namespace std;

//문제 2580번
#include <vector>
vector<pair<int,int>> v;
int map[10][10];
bool check(int x, int y, int val);
void dfs(int index);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cin >> map[i][j];
            if(map[i][j] == 0)
                v.push_back({i ,j});
        }
    }
    dfs(0);
}
bool check(int x, int y, int val){
    for(int i = 0;i<9;i++){//가로 체크
        if(map[x][i] == val)
            return false;
    }
    for(int i = 0;i<9;i++){//세로 체크
        if(map[i][y] == val)
            return false;
    }
    for(int i = (x / 3) * 3;i<(x/3) * 3 + 3;i++){//내부 체크
        for(int j = (y / 3) * 3; j<(y/3) * 3 + 3;j++){
            if(map[i][j] == val)
                return false;
        }
    }
    return true;
}
void dfs(int index){
    if(index == v.size()){
        for(int i = 0;i<9;i++){
            for(int j =0;j<9;j++){
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    int i;
    for(i=1;i<=9;i++){
        if(check(v[index].first, v[index].second, i)){
            map[v[index].first][v[index].second] = i;
            dfs(index + 1);
            map[v[index].first][v[index].second] = 0;
        }
    }
}