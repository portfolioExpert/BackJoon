#include <iostream>
#include <algorithm>
using namespace std;

//문제 14226번 이모티콘 -> BFS, DP
#include <queue>
int visit[1001][1001];//[복사한것][화면에있는것]
void bfs(){
    queue<pair<int,int>>q;//복사한 이미지, 현 화면에 떠있는 이미지 저장
    q.push({0, 1});
    visit[0][1] = 0;
    while(!q.empty()){
        int now = q.front().second;
        int copy = q.front().first;
        q.pop();

        //최대 1000개까지
        if(now > 1000 || copy > 1000)
            continue;

        //복사
        if(visit[now][now] > visit[copy][now] + 1){
            visit[now][now] = visit[copy][now] + 1;
            q.push({now, now});
        }
        //붙여 넣기
        if(now + copy <= 1000 && visit[copy][now + copy] > visit[copy][now] + 1){
            visit[copy][now + copy] = visit[copy][now] + 1;
            q.push({copy, now + copy});
        }

        //삭제
        if(now - 1 >= 0 && visit[copy][now - 1] > visit[copy][now] + 1){
            visit[copy][now - 1] = visit[copy][now] + 1;
            q.push({copy, now - 1});
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int s;
    cin >> s;
    for(int i = 0;i<=1000;i++){
        for(int j =0;j<=1000;j++){
            visit[i][j] = 987654321;
        }
    }
    bfs();
    int result = 987654321;
    for(int i = 0;i<=1000;i++){
        result = min(result, visit[i][s]);
    }
    cout << result;
}