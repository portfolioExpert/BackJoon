#include <iostream>
#include <algorithm>
using namespace std;

//문제 2133번
int result[31];
int dp(int x);
int main(){
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}
int dp(int x){
    if(x == 0)return 1;//경우의 수라서 3X0을 채우는방법은 아무것도 안 넣는 방법 1가지인가?
    if(x == 1)return 0;
    if(x == 2)return 3;
    if(result[x] != 0)return result[x];
    int after = 3*dp(x-2);
    for(int i = 3; i<=x;i++){
        if(i % 2 == 0){
            after += 2 * dp(x-i);
        }
    }
    return result[x] = after;
}