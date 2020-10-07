#include <iostream>
#include <algorithm>
using namespace std;

//문제 3041번
char ch[4][4];
int main(){
    int i, j, cnt = 0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cin >> ch[i][j];
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(ch[i][j] != '.'){
                cnt+= abs((ch[i][j] - 'A') / 4 -i) + abs((ch[i][j] - 'A') % 4 - j);
            }
        }
    }
    cout << cnt;
}