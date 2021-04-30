#include <iostream>
#include <algorithm>
using namespace std;

//문제 2023번
int n, cnt;
bool fx(int x);
void dfs(int x, int c);
int main(){
    cin >> n;
    if(n == 1){
        cout << 2 << "\n" << 3 << "\n" << 5 << "\n" << 7;
    }
    for(int i = 2;i<=7;i++){
        if(i == 2 || i == 3 || i == 5 || i == 7){
            dfs(i, 1);
        }
    }
    return 0;
}
bool fx(int x){//소수 판별 함수
    for(int i = 2; i * i <= x;i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
void dfs(int x, int c){
    if(c>n)return;
    for(int i = 1;i<=9;i++){
        int number = x * 10 +i;
        if(fx(number)){
            if(c == n - 1)
                cout << number << "\n";
            else
                dfs(number, c + 1);
        }
    }
}