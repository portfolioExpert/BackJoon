#include <iostream>
#include <algorithm>
using namespace std;

//문제 1065번
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, num[1001] = {0,};
    cin >> n;
    for(i=1;i<=99;i++){
        num[i] = i;
    }
    for(i=100;i<=n;i++){
        if((i % 100) / 10 - (i % 10) == (i % 1000) / 100 - (i % 100)/10)
            num[i] = num[i-1] + 1;
        else
            num[i] = num[i-1];
    }
    num[1000] = 144;
    cout << num[n];
    return 0;
}