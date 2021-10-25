//문제 12886번 돌 그룹 -> BFS
//세개의 그룹이지만 2개의 그룹으로 처리가능
#include <queue>
bool visit[1501][1501];
bool bfs(int a, int b, int c){
    queue<pair<int,int>>q;
    int sum = a+b+c;
    q.push({a,b});
    while(!q.empty()){
        int nowa = q.front().first;
        int nowb = q.front().second;
        q.pop();
        if(nowa == nowb && nowb == (sum - (nowa + nowb))){
            return 1;
        }
        visit[nowa][nowb] = 1;
        int arr[3] = {nowa, nowb, sum - (nowa + nowb)};
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(arr[i] < arr[j]){
                    int small = arr[i] + arr[i];
                    int big = arr[j] - arr[i];
                    if(visit[small][big] == 1)
                        continue;
                    visit[small][big] = 1;
                    q.push({small, big});
                }
            }
        }
    }
    return 0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    cout << bfs(a, b, c);
}