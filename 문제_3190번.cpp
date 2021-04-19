#include <iostream>
#include <algorithm>
using namespace std;

//문제 3190번
#include<queue>
#include<vector>
queue<pair<int,char>>q;
deque<pair<int,int>>snake;
int dx[4] = {0, 1 ,0, -1};
int dy[4] = {1, 0, -1, 0};
int n, Time;
int direct = 0;
int length = 1;
int map[101][101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, k, l;
    cin >> n;
    cin >> k;
    map[1][1] = 1;
    snake.push_front({1, 1});
    for(i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = 2;
    }
    cin >> l;
    for(i=0;i<l;i++){
        int t;
        char di;
        cin >> t >> di;
        q.push({t, di});
    }
    while(snake.front().first >= 1 && snake.front().first <= n && snake.front().second >=1 && snake.front().second <= n){

        int headx = snake.front().first;
        int heady = snake.front().second;

        //시간체크를하여 방향을 잡아주고
        if(Time == q.front().first){
            //오른쪽
            if(q.front().second == 'D')
                direct++;
            //왼쪽
            else
                direct+=3;
            q.pop();
        }

        //인덱스 관리
        direct%=4;

        //사과일 경우
        if(map[headx + dx[direct]][heady + dy[direct]] == 2){
            length++;
            map[headx + dx[direct]][heady + dy[direct]] = 0;
        }
        //벽일 경우 죽여야한다
        else if(map[headx + dx[direct]][heady + dy[direct]] == 1){
            Time++;
            break;
        }

        //0일 경우 머리를 증가시키고
        snake.push_front({headx + dx[direct], heady + dy[direct]});
        map[headx + dx[direct]][heady + dy[direct]] = 1;

        //꼬리를 길이만큼 잘라준다
        while(snake.size() > length){
            map[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        Time++;
    }
    cout << Time;
}