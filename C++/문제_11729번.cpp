#include <iostream>
#include <algorithm>
using namespace std;

//문제 11729번 재귀 이용
void hanoi(int x, int from, int second, int to);
int main(){
    int n, result = 1, i;
    cin >> n;
    for(i=0;i<n;i++){
        result*=2;
    }
    cout <<result-1 << "\n";
    hanoi(n, 1, 2, 3);
    return 0;
}
void hanoi(int x, int from, int second, int to){
    if(x == 1)cout << from << " " << to << "\n";
    else{
        hanoi(x-1, from, to, second);
        cout << from << " " << to << "\n";
        hanoi(x-1, second, from, to);
    }
}