//문제 17281 야구 -> 백트래킹, 시뮬레이션
int v[10];
int n, result;
int hit[51][10];
bool visit[10];
void dfs(int index){
    if(index == 10){
        int score = 0;
        int idx = 1;
        for(int i = 1;i<=n;i++){
            int out = 0;
            int base[4] = {0,0,0,0};
            for(int j = idx;;j++){
                if(j == 10)
                    j = 1;
                //아웃
                if(hit[i][v[j]] == 0){
                    out++;
                    //이닝 종료
                    if(out == 3){
                        idx = j + 1;
                        if(idx == 10)
                            idx = 1;
                        break;
                    }
                }
                //1루타
                else if(hit[i][v[j]] == 1){
                    if(base[3] == 1){
                        score++;
                        base[3] = 0;
                    }
                    for(int k = 2;k>=1;k--){
                        if(base[k] == 1){
                            base[k+1] = 1;
                            base[k] = 0;
                        }
                    }
                    base[1] = 1;
                }
                else if(hit[i][v[j]] == 2){
                    for(int k = 3;k>=2;k--){
                        if(base[k] == 1){
                            base[k] = 0;
                            score++;
                        }
                    }
                    if(base[1]){
                        base[3] = 1;
                        base[1] = 0;
                    }
                    base[2] = 1;
                }
                else if(hit[i][v[j]] == 3){
                    for(int k = 3;k>=1;k--){
                        if(base[k]){
                            score++;
                            base[k] = 0;
                        }
                    }
                    base[3] = 1;
                }
                else{
                    for(int k = 3;k>=1;k--){
                        if(base[k])
                            score++;
                        base[k] = 0;
                    }
                    score++;
                }
            }
        }
        if(result < score)
            result = max(result , score);
        return;
    }
    for(int i = 1;i<=9;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            v[i] = index;
            dfs(index + 1);
            visit[i] = 0;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=9;j++){
            cin >> hit[i][j];
        }
    }
    visit[4] = 1;
    v[4] = 1;
    dfs(2);
    cout << result;
}