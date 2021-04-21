#include <iostream>
#include <algorithm>
using namespace std;


//문제 17143번
#include <cstring>
typedef struct sharkpos{
    int s, d, z;
}sharkpos;
sharkpos map1[101][101], map2[101][101];
int sum , n, m, shark;
void catchshark(int i, int j);
void moveshark();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j = 1;
    cin >> n >> m >> shark;
    for(i=0;i<shark;i++){
        sharkpos pos;
        int r, c;
        cin >> r >> c >> pos.s >> pos.d >> pos.z;
        if(pos.s != 0){
            if(pos.d == 3 || pos.d == 4)
                pos.s = pos.s % (2 * m - 2);
            if(pos.d == 1 || pos.d == 2)
                pos.s = pos.s % (2 * n - 2);
        }
        map1[r][c] = pos;
    }

    while(j<=m){
        memset(map2, 0, sizeof(map2));//0으로 초기화
        catchshark(1, j);//상어 잡고
        moveshark();//상어 옮기고
        j++;//사람 옆으로 이동
        for(int k = 1;k <= n;k++){
            for(int t = 1;t <= m; t++){
                map1[k][t] = map2[k][t];
            }
        }
    }
    cout << sum;
    return 0;
}
void catchshark(int i, int j){
    while(i<=n){
        if(map1[i][j].z > 0){
            sum+=map1[i][j].z;//잡고
            map1[i][j].z = 0;//크기 0으로 두어 없는것처럼
            break;
        }
        i++;
    }
}
void moveshark(){
    int i, j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(map1[i][j].z == 0)//크기가 0 인 상어는 없으므로 다음으로 넘긴다
                continue;
            sharkpos sh = map1[i][j];
            int dis = 0;
            int x, y;
            x = i;
            y = j;
            while(dis < sh.s) {
                if(sh.d == 1){//방향이 위 일경우
                    if(x - 1 >= 1){
                        x--;
                        dis++;
                    }
                    else
                        sh.d = 2;
                }
                else if(sh.d == 2){//아래일 경우
                    if(x + 1 <= n){
                        x++;
                        dis++;
                    }
                    else
                        sh.d = 1;
                }
                else if(sh.d == 3){//오른쪽일 경우
                    if(y + 1 <= m){
                        y++;
                        dis++;
                    }
                    else
                        sh.d = 4;
                }
                else if(sh.d == 4){//왼쪽일 경우
                    if(y - 1 >= 1){
                        y--;
                        dis++;
                    }
                    else
                        sh.d = 3;
                }
            }
            if(map2[x][y].z > sh.z){//옮긴 상어보다 작을경우 삽입 안한다
                continue;
            }
            map2[x][y] = sh;
        }
    }
}