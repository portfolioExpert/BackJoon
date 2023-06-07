#include <iostream>
#include <algorithm>
using namespace std;

//문제 1735번 분수 합 -> 수학, 유클리드 호제법
typedef long long ll;
ll gcd(ll big, ll small){
    while(small > 0){
        ll save = big;
        big = small;
        small = save % small;
    }
    return big;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    ll a, b, c,d;
    cin >> a >> b;
    cin >> c >> d;

    //공약수
    ll gc = gcd(b, d);
    ll under = gc * b/gc * d/gc;
    ll upper = a * d/gc + c * b/gc;

    gc = gcd(max(under,upper), min(under,upper));
    cout << upper / gc << " " << under/gc;
}