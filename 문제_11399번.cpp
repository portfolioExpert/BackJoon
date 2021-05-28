#include <iostream>
#include <algorithm>
using namespace std;

//문제 11399번
int main(){
    int n, i , num[1001], sum = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num,num+n);
    for(i=0;i<n;i++){
        sum+=num[i];
        num[i] = sum;
    }
    sum = 0;
    for(i=0;i<n;i++){
        sum+=num[i];
    }
    cout << sum;
    return 0;
}