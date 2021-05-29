#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 2193번
typedef long long ll;
ll result[91];
ll dp(int x);
int main (){
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}
ll dp(int x){
    if(x<=2)return 1;
    if(result[x] != 0 )return result[x];
    return result[x] = dp(x-1) + dp(x-2);
}