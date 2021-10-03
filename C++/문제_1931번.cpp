#include <iostream>
#include <algorithm>
using namespace std;

//문제 1931번
typedef long long ll;
#include <vector>
vector <pair<ll,ll>> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, num1, num2, result = 1, i, in;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num1 >> num2;
        v.push_back({num2, num1});
    }
    sort(v.begin(), v.end());
    in = v[0].first;
    for(i=1;i<n;i++){
        if(in<=v[i].second){
            in = v[i].first;
            result++;
        }
    }
    cout << result;
    return 0;
}