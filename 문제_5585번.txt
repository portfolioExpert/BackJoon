#include <iostream>
#include <algorithm>
using namespace std;

//문제 5585번
int main(){
    int n, cnt = 0;
    cin >> n;
    n = 1000-n;
    while(n){
        if(n - 500 >= 0){
            n-=500;
            cnt++;
        }
        else if(n - 100 >= 0 && n - 500 < 0){
            n-=100;
            cnt++;
        }
        else if(n - 50 >= 0 && n - 100 < 0){
            n-=50;
            cnt++;
        }
        else if(n- 10 >=0 && n - 50 < 0){
            n-=10;
            cnt++;
        }
        else if(n - 5 >=0 && n-10 < 0){
            n-=5;
            cnt++;
        }
        else if(n-1>=0 && n-5 < 0){
            n-=1;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}