#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 1427번
bool compare(int a, int b){
    return a>b;
}
int main(){
    long long n, num[11], i, j;
    cin >> n;
    for(i=0;;i++){
        if(n==0)break;
        num[i] = n % 10;
        n/=10;
    }
    sort(num,num+i, compare);
    for(j=0;j<i;j++){
        cout << num[j];
    }
    return 0;
}