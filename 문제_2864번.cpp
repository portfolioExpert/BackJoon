#include <iostream>
#include <algorithm>
using namespace std;

//문제 2864번
int main(){
    int n1, n2, sum1, sum2, cnt = 1;
    cin >> n1 >> n2;
    sum1 = n1+n2;
    sum2 = n1+n2;
    while(n1){
        if(n1 % 10 == 6){
            sum2 -= cnt;
        }
        else if(n1 % 10 == 5){
            sum1 += cnt;
        }
        cnt*=10;
        n1/=10;
    }
    cnt = 1;
    while(n2){
        if(n2 % 10 == 6){
            sum2 -= cnt;
        }
        else if(n2 % 10 == 5){
            sum1 += cnt;
        }
        cnt*=10;
        n2/=10;
    }
    cout << sum2 << " " << sum1;
    return 0;
}