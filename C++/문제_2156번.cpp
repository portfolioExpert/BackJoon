#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 2156번
//if 문보다 max함수 호출이 빠르다 위에 보다 4ms 단축
int main(){
    int n, i , num[10005] = {0,}, result[10005] = {0,};
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> num[i];
    }
    result[1]=num[1];
    result[2]=num[2]+num[1];
    for(i=3;i<=n;i++){
        result[i] = max(result[i-1], num[i]+max(result[i-2], result[i-3] + num[i-1]));
    }
    cout << result[n];
    return 0;
}