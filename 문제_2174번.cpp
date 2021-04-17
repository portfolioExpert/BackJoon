#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>
typedef struct robot{
    int x, y ,dir;
}robot;
vector<robot> v;
//이거 때문임..
int dx[4] = {0, -1, 0, 1};//동 남 서 북
int dy[4] = {1, 0, -1, 0};
int n, m;
int visit[101][101];
bool crash;
void command(int num, char comm, int cnt);
int main(){
    int pos, comm, i;
    cin >> m >> n;
    cin >> pos >> comm;
    for(i = 1;i<=pos;i++){
        robot r;
        char ch;
        cin >> r.y >> r.x >> ch;
        switch(ch){
            case 'E': r.dir = 0;
                break;
            case 'S': r.dir = 1;
                break;
            case 'W': r.dir = 2;
                break;
            case 'N': r.dir = 3;
        }
        v.push_back(r);
        visit[r.x][r.y] = i;
    }
    for(i=0;i<comm;i++){
        int num, t;
        char comm;
        cin >> num >> comm >> t;
        command(num, comm, t);
    }
    if(crash == 0)
        cout << "OK";
}
void command(int num, char comm, int cnt){
    int number = num - 1;
    if(comm == 'R'){
        cnt %= 4;
        v[number].dir = (v[number].dir + cnt) % 4;
    }
    else if(comm == 'L'){
        cnt %= 4;
        v[number].dir = (v[number].dir + cnt * 3) % 4;
    }
    else if(comm == 'F' && crash == 0){
        for(int i = 0;i<cnt;i++){
            int gox = v[number].x + dx[v[number].dir];
            int goy = v[number].y + dy[v[number].dir];
            if(gox > n || gox < 1 || goy > m || goy < 1){
                crash = 1;
                cout << "Robot " << num <<" crashes into the wall" << "\n";
                break;
            }
            if(visit[gox][goy] != 0){
                crash = 1;
                cout << "Robot " << num << " crashes into robot " << visit[gox][goy];
                break;
            }
            visit[v[number].x][v[number].y] = 0;
            v[number].x = gox;
            v[number].y = goy;
            visit[gox][goy] = num;
        }
    }
}