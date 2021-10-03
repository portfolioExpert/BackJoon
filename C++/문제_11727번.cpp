#include <iostream>
#include <algorithm>
using namespace std;

//문제 11727번
int result[1001];
int dp(int n);
int main(){
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}
int dp(int n){
    if(n == 1)return 1;
    if(n == 2)return 3;
    if(result[n] != 0)return result[n];
    result[n] = (dp(n-1) + 2*dp(n-2)) % 10007;//이렇게 해야 시간초과가 안남 이유는 계산된 값을 리턴 해주기 때문, 한번에 리턴하면 계산을 하고 리턴해줘서 시간이 더 걸린다.
    return result[n];
}