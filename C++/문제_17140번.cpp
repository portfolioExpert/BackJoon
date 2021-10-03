//문제 17140번
#include <vector>
#include <cstring>
vector<pair<int,int>> v;
int row = 3, col = 3, result;
int map[101][101];
int change[101][101];
void rfx();
void cfx();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int r,c,k;
    cin >> r >> c >> k;
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){
            cin >> map[i][j];
        }
    }
    while(map[r][c] != k){
        if(result > 100){
            cout << -1;
            return 0;
        }
        if(row>=col)
            rfx();
        else
            cfx();
        memset(change, 0, sizeof(change));
        result++;
    }
    cout << result;
}
void rfx(){
    col = 0;
    for(int i = 1;i<=row;i++){
        int visit[101];
        vector<pair<int,int>>chan;
        memset(visit, 0, sizeof(visit));
        for(int j = 1;j<=100;j++){
            visit[map[i][j]]++;
        }
        for(int j = 1;j<=100;j++){
            if(visit[j] >= 1)
                chan.push_back({visit[j], j});
        }
        sort(chan.begin(), chan.end());
        int index = 0;
        for(int j = 1;index<chan.size();j+=2){
            change[i][j] = chan[index].second;
            change[i][j+1] = chan[index].first;
            index++;
        }
        col = max(col, (int)chan.size() * 2);
    }
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<=100;j++){
            map[i][j] = change[i][j];
        }
    }
}
void cfx(){
    row = 0;
    for(int i = 1;i<=col;i++){
        int visit[101];
        vector<pair<int,int>>chan;
        memset(visit, 0, sizeof(visit));
        for(int j = 1;j<=100;j++){
            visit[map[j][i]]++;
        }
        for(int j = 1;j<=100;j++){
            if(visit[j] >= 1)
                chan.push_back({visit[j], j});
        }
        sort(chan.begin(), chan.end());
        int index = 0;
        for(int j = 1;index<chan.size();j+=2){
            change[j][i] = chan[index].second;
            change[j+1][i] = chan[index].first;
            index++;
        }
        row = max(row, (int)chan.size() * 2);
    }
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<=100;j++){
            map[i][j] = change[i][j];
        }
    }
}