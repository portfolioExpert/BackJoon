#include <iostream>
#include <algorithm>
Using namespace std;
int dp[100];
int fibonacci(int n);
int main(){
    int n, i,num;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        if(num == 0)
            cout << "1 " << 0 << "\n";
        else
            cout << fibonacci(num-1) << " " << fibonacci(num) << "\n";
    }
    return 0;
}
int fibonacci(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    if(dp[n] != 0)return dp[n];
    return dp[n] = fibonacci(n-1) + fibonacci(n-2);
}
