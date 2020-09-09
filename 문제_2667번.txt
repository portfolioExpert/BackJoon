#include <iostream>
#include <algorithm>
using namespace std;

//문제 2667번
#include <queue>
#include <string>
queue <pair<int,int>> q;
int dx[4] = {0 ,0 , 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool visit[26][26];
int n;
char ch[26][26];//왜 문자 자료형은안될까?
int bfs(int x, int y, int cnt);
int main(){
    int i, j, cnt = 0, result[626], k = 0;//단지수가 총 625/2개 이므로 result값을 626로 두웠음
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> ch[i][j];//왜 스캔에프로 해야하지?
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(visit[i][j] == 0 && ch[i][j] == '1'){
                result[k++] = bfs(i, j, 0);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    sort(result,result+cnt);
    for(i=0;i<cnt;i++){
        cout << result[i] << "\n";
    }
    return 0;
}
int bfs(int x, int y, int cnt){
    visit[x][y] = 1;
    q.push({x, y});
    cnt++;
    while(!q.empty()){
        int po1, po2;
        po1 = q.front().first;
        po2 = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int cha1, cha2;
            cha1 = po1+dx[i];
            cha2 = po2+dy[i];
            if(cha1 >= 1 && cha1<= n && cha2 >= 1 && cha2 <= n &&ch[cha1][cha2] == '1'  && visit[cha1][cha2] == 0){//if문을 쓸때 배열 조건 말고 범위 조건 이후 배열 조건을 써주면 굳이 if문을 두개말고 하나로 처리 가능하다
                q.push({cha1, cha2});
                visit[cha1][cha2] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}