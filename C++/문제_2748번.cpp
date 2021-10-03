#include <iostream>
#include <algorithm>
using namespace std;

//문제 2748번
long long result[91];
long long fibonacci(long long x);
int main(){
    long long n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
long long fibonacci(long long x){
    if(x <= 1)return x;
    if(result[x] != 0)return result[x];
    return result[x] = fibonacci(x-1) + fibonacci(x-2);
}