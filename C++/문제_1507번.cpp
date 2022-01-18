//문제 1507번 궁금한 민호 -> 플로이드 와샬 응용
int result;
int map[21][21];
bool visit[21][21];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> map[i][j];
            visit[i][j] = false;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == j)
                continue;
            for(int k = 1;k<=n;k++){
                if(i == k || j == k)
                    continue;
                //최소 거리가 맞지 않을 경우 불가능하므로
                if(map[j][k] > map[j][i] + map[i][k]){
                    cout << -1;
                    return 0;
                }
                //사용 불가한 길이다
                if(map[j][k] == map[j][i] + map[i][k]){
                    visit[j][k] = true;
                }
            }
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = i + 1;j<=n;j++){
            //사용가능한 길만 체크
            if(visit[i][j] == false)
                result+=map[i][j];
        }
    }
    cout << result;
    return 0;
}