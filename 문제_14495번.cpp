#include <iostream>
#include <algorithm>
using namespace std;

//문제 14495번
long long num[117] = {1, 1, 1};
int main(){
    int n, i;
    cin >> n;
    for(i=3;i<n;i++){
        num[i] = num[i-1] + num[i-3];
    }
    cout << num[n-1];
    return 0;
}