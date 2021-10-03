#include <iostream>
#include <algorithm>
using namespace std;

//문제 10872번
int fact(int x);
int main(){
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}
int fact(int x){
    int i ,result = 1;
    for(i=1;i<=x;i++){
        result*=i;
    }
    return result;
}