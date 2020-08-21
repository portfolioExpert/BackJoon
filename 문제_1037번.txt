#include <iostream>
#include <algorithm>
using namespace std;

//문제 1037번
int main(){
    long long n, i, num[51];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num, num+n);
    cout << num[0] * num[n-1];
    return 0;
}