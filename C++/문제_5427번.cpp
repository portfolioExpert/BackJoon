#include <iostream>
#include <algorithm>
using namespace std;

//문제 5427번
#include <queue>
queue <pair<int, int>> hq;
queue <pair<int, int>> fq;
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int firevisit[1001][1001];
int humanvisit[1001][1001];
char map[1001][1001];
int result, m, n;
bool flag;
void fireBFS();
void humanBFS();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, i, j, k;
    cin >> t;
    for(i=0;i<t;i++){
        flag = 0;
        cin >> m >> n;
        for(j = 0; j<n;j++){
            for(k=0;k<m;k++){
                cin >> map[j][k];
                if(map[j][k] == '@'){
                    hq.push({j, k});
                    humanvisit[j][k] = 1;
                }
                if(map[j][k] == '*'){
                    fq.push({j, k});
                    firevisit[j][k] = 1;
                }
            }
        }
        fireBFS();//fire부터 디피로 처리해두고
        humanBFS();//사람을 디피로 처리한다
        if(flag){
            cout << result << "\n";
        }
        else
            cout << "IMPOSSIBLE" << "\n";
        result = 0;

        //큐와 방문디피를 초기화
        while(!fq.empty()){
            fq.pop();
        }
        while(!hq.empty()){
            hq.pop();
        }
        for(j=0;j<n;j++){
            fill_n(firevisit[j], m, 0);
            fill_n(humanvisit[j], m ,0);
        }
    }
}

void fireBFS(){
    while(!fq.empty()){

        int gofx = fq.front().first;
        int gofy = fq.front().second;
        fq.pop();
        for(int i = 0; i< 4;i++){
            int chx = gofx+dx[i];
            int chy = gofy+dy[i];
            if(chx<0 || chx >= n || chy < 0 || chy >= m){//어차피 벽에 둘러쌓여있어서
                continue;
            }
            if(firevisit[chx][chy] == 0 && map[chx][chy] != '#'){
                firevisit[chx][chy] = firevisit[gofx][gofy] + 1;
                fq.push({chx, chy});
            }
        }
    }
}

void humanBFS(){
    while(!hq.empty()){
        int gox = hq.front().first;
        int goy = hq.front().second;
        hq.pop();
        int cnt = 0;
        for(int i = 0;i<4;i++){
            int chx = gox+dx[i];
            int chy = goy+dy[i];
            if((chx<0 || chx >= n || chy < 0 || chy >= m) && (humanvisit[gox][goy] < firevisit[gox][goy] || firevisit[gox][goy] == 0)){//어차피 벽에 둘러쌓여있어서
                result = humanvisit[gox][goy];
                flag = 1;
                return;
            }

            if(chx>= 0 && chx < n && chy >= 0 && chy < m && humanvisit[chx][chy] == 0 && (firevisit[chx][chy] > humanvisit[chx][chy] + 1 || firevisit[chx][chy] == 0) && map[chx][chy] != '#'){
                humanvisit[chx][chy] = humanvisit[gox][goy] + 1;
                hq.push({chx, chy});
            }
            if(map[chx][chy] == '#')//주위에 벽일때 횟수를 올린다
                cnt++;
        }
        if(cnt == 4)//주위에 전부 벽일때 처리
            return;
    }
}