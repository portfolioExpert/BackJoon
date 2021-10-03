//문제 14890번 빡 구 현
#include <cstring>
int map[101][101];
bool block[101][101];
int n, l, result = 0;
bool test(int x, int y, int pos, int val);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j;
    cin >> n >> l;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(i = 0;i<n;i++){
        for(j = 0;j<n-1;j++){
            if(abs(map[i][j] - map[i][j+1]) >= 2)
                break;
            if(map[i][j] < map[i][j+1]){
                if(test(i, j, 1, map[i][j]) == 1)
                    continue;
                else
                    break;
            }
            else if(map[i][j] > map[i][j+1]){
                if(test(i, j, 2, map[i][j+1]) == 1)
                    continue;
                else
                    break;
            }
        }
        if(j==n-1)
            result++;
    }
    memset(block, 0 ,sizeof(block));
    for(i = 0;i<n;i++){
        for(j = 0;j<n-1;j++){
            if(abs(map[j][i] - map[j+1][i]) >= 2)
                break;
            if(map[j][i] < map[j+1][i]){
                if(test(j, i, 3, map[j][i]) == 1)
                    continue;
                else
                    break;
            }
            else if(map[j][i] > map[j+1][i]){
                if(test(j, i, 4, map[j+1][i]) == 1)
                    continue;
                else
                    break;
            }
        }
        if(j==n-1)
            result++;
    }

    cout << result;
}
bool test(int x, int y, int pos, int val){
    int cnt = 0;
    if(pos == 1){
        for(int i = y; i>=0 ;i--){
            if(cnt == l)break;
            if(map[x][i] == val && block[x][i] ==0)
                cnt++;
            else
                return false;
        }
        if(cnt < l)return false;
        for(int i = y; cnt > 0; i--){
            block[x][i] = 1;
            cnt--;
        }
    }
    else if(pos == 2){
        for(int i = y+1; i<n ;i++){
            if(cnt == l)break;
            if(map[x][i] == val && block[x][i] == 0)
                cnt++;
            else
                return false;
        }
        if(cnt < l)return false;
        for(int i = y + 1; cnt > 0; i++){
            block[x][i] = 1;
            cnt--;
        }
    }
    else if(pos == 3){
        for(int i = x; i>=0 ;i--){
            if(cnt == l)break;
            if(map[i][y] == val && block[i][y] ==0)
                cnt++;
            else
                return false;
        }
        if(cnt < l)return false;
        for(int i = x; cnt > 0; i--){
            block[i][y] = 1;
            cnt--;
        }
    }
    else if(pos == 4){
        for(int i = x + 1; i<n ;i++){
            if(cnt == l)break;
            if(map[i][y] == val && block[i][y] == 0)
                cnt++;
            else
                return false;
        }
        if(cnt < l)return false;
        for(int i = x + 1; cnt > 0; i++){
            block[i][y] = 1;
            cnt--;
        }
    }
    return true;
}