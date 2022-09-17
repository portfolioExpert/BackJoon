#include <iostream>
#include <algorithm>
using namespace std;

//문제 1351번 무한 수열 -> DP, 맵
typedef long long ll;
#include <map>
map<ll, ll>m;
ll n, p, q;
ll topdown(ll i){
    if(i == 0)
        return 1;
    if(m[i] != 0)
        return m[i];
    return m[i] = topdown(i/p) + topdown(i/q);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> p >> q;
    cout << topdown(n);
}