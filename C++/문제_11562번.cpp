//문제 11562번 백양로 브레이크 -> 플로이드 와샬
int map[251][251];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            map[i][j] = 999999;
        }
        map[i][i] = 0;
    }
    for(int i = 0;i<m;i++){
        int u, v, b;
        cin >> u >> v >> b;
        if(b == 0){
            map[u][v] = 0;
            map[v][u] = 1;
        }
        else{
            map[u][v] = 0;
            map[v][u] = 0;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
            }
        }
    }

    int ask;
    cin >> ask;
    for(int i = 0;i<ask;i++){
        int s, e;
        cin >> s >> e;
        cout << map[s][e] << "\n";
    }
}