#include <iostream>
#include <algorithm>
using namespace std;

//문제 17779번 게리멘더링 2 -> 구현, 시뮬레이션
//0. 기준점에 따라 d1, d2를 정해야되고
//1. 5번 선거구를 결정하고
//2. 1,2,3,4번 선거구를 결정하면서 각자 인구를 센다.
//3. max값과 min값을 구해 빼주고
//4. 1~3을 반복

#include <cstring>
int map[21][21];
int visit[21][21];//선거구 결정 짓기
int result = 987654321;
int dx[4] = {1, 1 ,-1, -1};
int dy[4] = {-1, 1 ,1, -1};
int total[6];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> map[i][j];
        }
    }

    //x
    for(int i = 1;i<=n;i++){
        //y
        for(int j = 1;j<=n;j++){
            //d1
            for(int k = 1;k<=n;k++){
                //d2
                for(int t = 1;t<=n;t++){
                    if(i + k + t > n || j + t > n)
                        continue;
                    if(0 >= j - k || j - k >= j)
                        continue;

                    memset(visit, 0, sizeof(visit));
                    memset(total, 0, sizeof(total));
                    int maxval = 0;
                    int minval = 987654321;
                    //경계선 그리고
                    //시작지점
                    int gox = i;
                    int goy = j;
                    int d1 = k;
                    int d2 = t;

                    while(visit[gox][goy] == 0){
                        int index = 0;

                        visit[gox][goy] = 5;
                        total[5]+=map[gox][goy];
                        while(index < 4){
                            if(index % 2 == 0){
                                for(int h = 0;h<d1;h++){
                                    if(visit[gox][goy] == 0){
                                        visit[gox][goy] = 5;
                                        total[5] += map[gox][goy];
                                    }
                                    gox+=dx[index];
                                    goy+=dy[index];
                                }
                            }
                            else{
                                for(int h = 0;h<d2;h++){
                                    if(visit[gox][goy] == 0){
                                        visit[gox][goy] = 5;
                                        total[5] += map[gox][goy];
                                    }
                                    gox+=dx[index];
                                    goy+=dy[index];
                                }
                            }
                            index++;
                        }
                        d1--;
                        d2--;
                        gox +=1;
                    }

                    //1.
                    for(int w = 1;w < i + k;w++){
                        for(int h = 1;h<=j;h++){
                            if(visit[w][h] == 0){
                                visit[w][h] = 1;
                                total[1]+=map[w][h];
                            }
                        }
                    }
                    //2.
                    for(int w = 1;w<=i + t;w++){
                        for(int h = j + 1;h<=n;h++){
                            if(visit[w][h] == 0){
                                visit[w][h] = 2;
                                total[2]+=map[w][h];
                            }
                        }
                    }
                    //3.
                    for(int w = i + k;w<=n;w++){
                        for(int h = 1;h<j - k + t;h++){
                            if(visit[w][h] == 0){
                                visit[w][h] = 3;
                                total[3]+=map[w][h];
                            }
                        }
                    }
                    //4.
                    for(int w = i + t + 1;w<=n;w++){
                        for(int h = j - k + t;h<=n;h++){
                            if(visit[w][h] == 0){
                                visit[w][h] = 4;
                                total[4]+=map[w][h];
                            }
                        }
                    }
                    for(int i = 1;i<=5;i++){
                        maxval = max(maxval, total[i]);
                        minval = min(minval, total[i]);
                    }
                    result = min(result, maxval - minval);

                }
            }
        }
    }
    cout << result;
}