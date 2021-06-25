//문제 17822번
#include <cstring>
int cir[51][51];
bool check[51][51];
int n, m, t;
void move(int x, int d, int k);
void del();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m >> t;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<m;j++){
            cin >> cir[i][j];
        }
    }
    while(t>0){
        int x, d, k;
        cin >> x >> d >> k;
        move(x, d, k);
        del();
        t--;
    }
    int result = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<m;j++){
            result+=cir[i][j];
        }
    }
    cout << result;
}
void move(int x, int d, int k){
    if(d == 0){
        for(int i = x;i<=n;i+=x){
            for(int j = 0;j<k;j++){
                int save = cir[i][m-1];
                for(int t = m - 1;t>=1;t--){
                    cir[i][t] = cir[i][t-1];
                }
                cir[i][0] = save;
            }
        }
    }
    else if(d == 1){
        for(int i = x;i<=n;i+=x){
            for(int j = 0;j<k;j++){
                int save = cir[i][0];
                for(int t = 0;t<m - 1;t++){
                    cir[i][t] = cir[i][t + 1];
                }
                cir[i][m-1] = save;
            }
        }
    }
}
void del(){
    bool near = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<m;j++){
            bool flag = 0;
            if(cir[i][j] != 0){
                //오른쪽
                if(cir[i][j] == cir[i][(j+1) % m]){
                    check[i][(j+1) % m] = 1;
                    near = 1;
                    flag = 1;
                }
                //왼쪽
                if(cir[i][j] == cir[i][(j-1+m) % m]){
                    check[i][(j-1+m) % m] = 1;
                    near = 1;
                    flag = 1;
                }
                //다른 인접 원
                if(i + 1 <= n && cir[i][j] == cir[i+1][j]){
                    check[i+1][j] = 1;
                    near = 1;
                    flag = 1;
                }
                if(i - 1 >= 1 && cir[i][j] == cir[i-1][j]){
                    check[i-1][j] = 1;
                    near = 1;
                    flag = 1;
                }
                if(flag)
                    check[i][j] = 1;
            }
        }
    }
    if(near == 1){
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<m;j++){
                if(check[i][j] == 1)
                    cir[i][j] = 0;
            }
        }
    }
    else{
        double avg = 0;
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            for(int k =0;k<m;k++){
                if(cir[i][k] > 0){
                    avg+=cir[i][k];
                    cnt++;
                }
            }
        }
        avg/=cnt;
        for(int i = 1;i<=n;i++){
            for(int k = 0;k<m;k++){
                if(cir[i][k] != 0 && avg>cir[i][k])
                    cir[i][k]++;
                else if(cir[i][k] != 0 && avg < cir[i][k])
                    cir[i][k]--;
            }
        }
    }
    memset(check, 0, sizeof(check));
}