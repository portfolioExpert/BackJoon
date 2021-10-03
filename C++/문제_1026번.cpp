#include <iostream>
#include <algorithm>
using namespace std;

//문제 1026번
bool big(int x, int y);
int main(){
    int n, i, num1[51], num2[51], sum = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num1[i];
    }
    sort(num1,num1+n, big);
    for(i=0;i<n;i++){
        cin >> num2[i];
    }
    sort(num2,num2+n);
    for(i=0;i<n;i++){
        sum+=(num1[i]*num2[i]);
    }
    cout << sum;
    return 0;
}
bool big(int x, int y){
    return x > y;
}