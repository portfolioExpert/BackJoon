#include <iostream>
#include <algorithm>
using namespace std;

//문제 1475번
int main(){
    int n, result = -1, set[10] = {0}, sum;
    cin >> n;
    if(n == 0){
        cout << 1;
        return 0;
    }
    while(n){
        set[n % 10]++;
        n/=10;
    }
    sum = set[6] + set[9];
    if(sum % 2 == 0){
        set[6] = sum/2;
        set[9] = sum/2;
    }
    else{
        set[6] = (sum+1)/2;
        set[9] = (sum+1)/2;
    }
    for(int i = 0; i<10;i++){
        result = max(result, set[i]);
    }
    cout << result;
    return 0;
}