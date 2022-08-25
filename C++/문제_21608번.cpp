#include <iostream>
#include <algorithm>
using namespace std;

//문제 21608번 상어 초등학교 -> 구현
#include <vector>
int result[21][21];
int emp[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0 ,-1 ,0, 1};
int n;
vector<pair<int,vector<int>>>v;
//주변에 인접한 학생 중 좋아하는 사람의 수를 구하는 것
int firstCheck(int x, int y, int index){
    int res = 0;
    for(int i = 0;i<4;i++){
        int gox = x + dx[i];
        int goy = y + dy[i];
        if(gox < 0 || gox >= n || goy < 0 || goy >= n || result[gox][goy] == 0)
            continue;
        for(int j = 0;j<4;j++){
            if(v[index].second[j] == result[gox][goy]){
                res++;
            }
        }
    }
    return res;
}
//주변 빈칸의 개수 감소
void nearDown(int x, int y){
    for(int i = 0;i<4;i++){
        int gox = x + dx[i];
        int goy = y + dy[i];
        if(gox >= 0 && gox < n && goy >= 0 && goy < n && emp[gox][goy] > 0){
            emp[gox][goy]--;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int res = 0;
    cin >> n;
    for(int i = 0;i<n * n;i++){
        int num, st1, st2, st3, st4;
        cin >> num >> st1 >> st2 >> st3 >> st4;
        vector<int>stu;
        stu.push_back(st1);
        stu.push_back(st2);
        stu.push_back(st3);
        stu.push_back(st4);
        v.push_back({num, stu});
    }
    //사전 작업
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int sum = 0;
            for(int k = 0;k<4;k++){
                int gox = i + dx[k];
                int goy = j + dy[k];
                if(gox >= 0 && gox < n && goy>=0 && goy < n){
                    sum++;
                }
            }
            emp[i][j] = sum;
        }
    }

    //모든 사람 순서대로 넣은 것을 배치
    for(int k = 0;k<v.size();k++){
        int likesum = 0;//좋아하는 학생의 인접한 칸의 최대 값
        vector<pair<int,int>>liked;
        vector<pair<int,int>>empcnt;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                //현재 비어있는 칸이면
                if(result[i][j] == 0){
                    //좋아하는 학생이 주변에 몇명인지 세어보고
                    int countlike = firstCheck(i, j, k);
                    //좋아하는 학생이 많다면 최신화하고 좌표 저장
                    if(likesum < countlike){
                        likesum = countlike;
                        liked.clear();
                        liked.push_back({i, j});
                    }
                    //좋아하는 학생의 수가 같다면
                    else if(likesum == countlike){
                        liked.push_back({i, j});
                    }
                }
                else
                    continue;
            }
        }
        //1번 조건
        if(liked.size() == 1){
            result[liked[0].first][liked[0].second] = v[k].first;
            nearDown(liked[0].first, liked[0].second);
        }
        else if(liked.size() > 1){
            int val = -1;
            for(auto y : liked){
                if(val < emp[y.first][y.second]){
                    val = emp[y.first][y.second];
                    empcnt.clear();
                    empcnt.push_back({y.first, y.second});
                }
                else if(val == emp[y.first][y.second]){
                    empcnt.push_back({y.first, y.second});
                }
            }
            //2번조건
            if(empcnt.size() == 1){
                result[empcnt[0].first][empcnt[0].second] = v[k].first;
            }
            //3번조건
            else if(empcnt.size() > 1){
                sort(empcnt.begin(), empcnt.end());
                result[empcnt[0].first][empcnt[0].second] = v[k].first;
            }
            nearDown(empcnt[0].first, empcnt[0].second);
        }
    }

    //결과 값
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int index = 0;
            for(int k = 0;k<v.size();k++){
                if(v[k].first == result[i][j]){
                    index = k;
                    break;
                }
            }
            int val = firstCheck(i, j, index);
            switch(val){
                case 1: res+=1;
                    break;
                case 2: res+=10;
                    break;
                case 3: res+=100;
                    break;
                case 4: res+=1000;
                    break;
            }
        }
    }
    cout << res;
}