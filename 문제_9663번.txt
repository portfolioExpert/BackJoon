#include <iostream>
#include <algorithm>
using namespace std;

//문제 9663번
int n, result, queen[16];//배열은 퀸을 열로 배치한 위치가 들어간다
bool fx(int x);
void dfs(int x);
int main(){
    cin >> n;
    dfs(1);//1번째 퀸부터 배치
    cout << result;
    return 0;
}
bool fx(int x){
    for(int i = 1;i<x;i++){
        if(queen[x] == queen[i] || x-i == abs(queen[x] - queen[i])){//직선에 있을때와, 대각선에 있을때는 안되므로
            return false;
        }
    }
    return true;//이외는 배치가능
}
void dfs(int x){
    if(x ==n+1){//체스판이 완성되었을때 횟수증가
        result++;
        return;
    }
    for(int i = 1;i <=n ;i++){
        queen[x] = i;
        if(fx(x))
            dfs(x+1);//퀸을계속 배치
    }
}