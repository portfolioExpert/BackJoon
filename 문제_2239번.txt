#include <iostream>
#include <algorithm>
using namespace std;

//문제 2239번
#include <vector>
vector<pair<int,int>> v;
string map[10];
bool colum[10][10];
bool row[10][10];
bool check(int x, int y, char val);
void dfs(int index);
int main(){
    int i, j;
    for(i=0;i<9;i++){
        cin >> map[i];
    }
    for(i = 0;i<9;i++){
        for(j=0;j<9;j++){
            if(map[i][j] == '0')
                v.push_back({i,j});
            else{
                colum[i][map[i][j] - 48] = 1;//행에 값이 있다
                row[j][map[i][j] - 48] = 1;//열에 값이 있다.
            }
        }
    }
    dfs(0);
    return 0;
}
bool check(int x, int y, char val){
    int i ,j;
    for(i = (x / 3) * 3;i < (x / 3) * 3 + 3;i++){
        for(j = (y / 3) * 3; j < (y / 3) * 3 + 3;j++){
            if(map[i][j] == val)
                return false;
        }
    }
    return true;
}
void dfs(int index){
    if(index == v.size()){
        for(int i =0;i<9;i++){
            for(int j = 0;j<9;j++){
                cout << map[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    int i;
    for(i=1;i<=9;i++){
        if(colum[v[index].first][i] == 0 && row[v[index].second][i] == 0){
            if(check(v[index].first, v[index].second, i + 48)){
                map[v[index].first][v[index].second] = i + 48;
                colum[v[index].first][i] = 1;
                row[v[index].second][i] = 1;
                dfs(index+1);
                map[v[index].first][v[index].second] = '0';
                colum[v[index].first][i] = 0;
                row[v[index].second][i] = 0;
            }
        }
    }
}