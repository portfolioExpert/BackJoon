//문제 17837번 새로운 게임2 -> 시뮬레이션
#include <vector>
typedef struct horse{
    int row;
    int column;
    int direct;
    int num;
}horse;
int cnt = 0;
int n, k;
int map[13][13];
vector<int> info[13][13];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    horse h[11];
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<k;i++){
        int input1, input2, input3;
        cin >> input1 >> input2 >> input3;
        h[i].row = input1;
        h[i].column = input2;
        h[i].direct = input3;
        h[i].num = i;
        info[input1][input2].push_back(i);
    }
    while(1){
        cnt++;
        //종료 조건
        if(cnt >=1000)
            break;
        //이동
        for(int i = 0;i<k;i++){
            //현재 위치
            int nowx = h[i].row;
            int nowy = h[i].column;
            int d = h[i].direct;
            //이동할 위치
            int afterx = nowx + dx[d];
            int aftery = nowy + dy[d];
            int afterd = d;
            //나간 경우, 파랑색 경우 방향만 반대후 이동
            if(afterx <= 0 || afterx > n || aftery <= 0 || aftery > n || map[afterx][aftery] == 2){
                //방향 변환
                switch(d){
                    case 1:
                        afterd = 2;
                        break;
                    case 2:
                        afterd = 1;
                        break;
                    case 3:
                        afterd = 4;
                        break;
                    case 4:
                        afterd = 3;
                        break;
                    default:
                        break;
                }
                //변환한 방향으로 이동
                afterx = nowx + dx[afterd];
                aftery = nowy + dy[afterd];

                //이동
                h[i].row = afterx;
                h[i].column = aftery;
                h[i].direct = afterd;

                //움직이는 곳 위치가 파랑일 경우 방향만 변환
                if(afterx <= 0 || afterx > n || aftery <= 0 || aftery > n || map[afterx][aftery] == 2){
                    h[i].row = nowx;
                    h[i].column = nowy;
                    continue;
                }
            }
            //해당 숫자 찾기
            auto index = find(info[nowx][nowy].begin(), info[nowx][nowy].end(), h[i].num);
            //빨간색
            if(map[afterx][aftery] ==1){
                reverse(index, info[nowx][nowy].end());
            }
            //이동
            for(auto j = index;j != info[nowx][nowy].end();j++){
                h[*j].row = afterx;
                h[*j].column = aftery;
                info[afterx][aftery].push_back(*j);
            }
            info[nowx][nowy].erase(index, info[nowx][nowy].end());
            //사이즈 4이상일 경우 종료
            for(int i = 0;i<k;i++){
                if(info[h[i].row][h[i].column].size() >= 4){
                    cout << cnt;
                    return 0;
                }
            }
        }
    }
    if(cnt>=1000)
        cout << -1;
    else
        cout << cnt;
}