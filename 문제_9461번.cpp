#include <iostream>
#include <algorithm>
using namespace std;

//문제 9461번
typedef long long ll;
ll result[101];
ll tryangle(ll x);
int main(){
    int n, i, num;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        cout << tryangle(num) << "\n";
    }
    return 0;
}
ll tryangle(ll x){
    if(x == 0)return 0;
    if(x <= 3)return 1;
    if(result[x] != 0)return result[x];
    return result[x] = tryangle(x-2) + tryangle(x-3);
}