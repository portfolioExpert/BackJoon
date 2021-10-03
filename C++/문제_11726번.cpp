#include <iostream>
#include <algorithm>
using namespace std;

int result[1001];
int dp(int x);
int main(){
    int n;
    cin >> n;
    cout << dp(n);
    return 0;
}
int dp(int x){
    if(x == 1)return 1;
    if(x == 2)return 2;
    if(result[x] != 0)return result[x];
    return result[x] = dp(x-1) + dp(x-2) % 10007;
}