#include <iostream>
#include <algorithm>
using namespace std;

//문제 15686번
#include <vector>
vector <pair<int, int>> house;
vector <pair<int, int>> chi;
int map[51][51];
bool visit[14];//치킨집 방문
int n ,m, result = 987654321;
int totaldis();
void dfs(int index, int cnt);
int main(){
    int i, j;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 1)//집 좌표 넣고
                house.push_back({i,j});
            if(map[i][j] == 2)//치킨집 좌표 넣고
                chi.push_back({i,j});
        }
    }
    dfs(-1, 0);
    cout << result;
}
int totaldis(){
    int sum = 0;
    for(int i = 0; i<house.size();i++){
        int mini = 999999999;
        for(int j = 0;j<chi.size();j++){//집에서 치킨집까지 최단거리 찾기
            if(visit[j] == 1)
                mini = min(abs(house[i].first - chi[j].first) + abs(house[i].second - chi[j].second), mini);
        }
        sum+=mini;//거리를 더해서
    }
    return sum;//출력
}
void dfs(int index, int cnt){
    if(cnt == m){//치킨집이 많으면 많을수록 최단거리가 많아지므로 최대까지 이용
        result = min(result, totaldis());//그때 각 집에서 치킨집까지 거리를 구한다
        return;
    }
    for(int i = index + 1;i<chi.size();i++){//백트래킹으로 치킨집을 없애보며 최단거리를 구함
        visit[i] = 1;
        dfs(i, cnt + 1);
        visit[i] = 0;
    }
}