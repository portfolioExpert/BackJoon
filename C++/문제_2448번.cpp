#include <iostream>
#include <algorithm>
using namespace std;

//문제 2448번 별찍기 - 11 -> 재귀, 분할정복
char arr[4001][8001];
void div(int size, int x, int y) {
    //기저는 3
    if (size == 3) {
        arr[x][y] = '*';
        //왼쪽아래
        arr[x + 1][y - 1] = '*';
        //오른쪽 아래
        arr[x + 1][y + 1] = '*';

        //맨아래 줄
        arr[x + 2][y] = '*';
        arr[x + 2][y - 1] = '*';
        arr[x + 2][y - 2] = '*';
        arr[x + 2][y + 1] = '*';
        arr[x + 2][y + 2] = '*';
        return;
    }
    else {
        //위에
        div(size / 2, x, y);
        //왼쪽
        div(size / 2, x + size / 2, y - size / 2);
        //오른쪽
        div(size / 2, x + size / 2, y + size / 2);
        return;
    }
}
int main(){
    for(int i = 0;i<4000;i++){
        for(int j = 0;j<8000;j++){
            arr[i][j] = ' ';
        }
    }
    int n;
    cin >> n;
    div(n, 0, n-1);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<2 * n - 1;j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}