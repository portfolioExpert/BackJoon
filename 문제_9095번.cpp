#include <iostream>
#include <algorithm>
using namespace std;

//문제 9095번
int result[12];
int dp(int x);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i, num;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        cout << dp(num) << "\n";
    }
    return 0;
}
int dp(int x){
    if(x == 1)return 1;
    if(x == 2)return 2;
    if(x == 3)return 4;
    return result[x] = dp(x-1) + dp(x-2) + dp(x-3);
}