#include <iostream>
#include <algorithm>
using namespace std;

//문제 14891번
#include <cstring>
char arr[4][2][9];
int visit[5];
void fx(int number, int pos);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j, t, result = 0, num = 1;;
    for(i=0;i<4;i++){
        for(j=0;j<8;j++){
            cin >> arr[i][0][j];
        }
    }
    cin >> t;
    for(i=0;i<t;i++){
        int number, pos;
        memset(visit, 0, sizeof(visit));
        cin >> number >> pos;
        visit[number] = 1;
        fx(number, pos);
    }
    //톱니바퀴의 12시 위치가 1 이면 S극이므로 더해줘야한다
    for(i=0;i<4;i++){
        if(arr[i][0][0] == '1'){
            result+=num;
        }
        num*=2;
    }
    cout << result;
}
void fx(int number, int pos){
    if(number < 1 || number > 4)return;
    //방문 하지 않고 왼쪽으로 진행할때
    if(number - 1 >= 1 && visit[number - 1] == 0 && arr[number-2][0][2] != arr[number-1][0][6]){
        visit[number-1] = 1;
        fx(number-1, -pos);
    }
    //방문하지 않고 오른쪽으로 진행할때
    if(number + 1 <= 4 && visit[number + 1] == 0 && arr[number-1][0][2] != arr[number][0][6]){
        visit[number + 1] = 1;
        fx(number + 1, -pos);
    }
    //바뀐 위치 삽입
    if(pos == 1){
        int save = arr[number-1][0][7];
        for(int i = 7;i>=1;i--){
            arr[number-1][1][i] = arr[number-1][0][i-1];
        }
        arr[number-1][1][0] = save;
    }
    else{
        int save = arr[number-1][0][0];
        for(int i = 0;i<7;i++){
            arr[number-1][1][i] = arr[number-1][0][i+1];
        }
        arr[number-1][1][7] = save;
    }
    //원래 위치에 삽입
    for(int i=0;i<8;i++){
        arr[number-1][0][i] = arr[number-1][1][i];
    }
}