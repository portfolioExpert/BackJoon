#include <iostream>
#include <algorithm>
using namespace std;

//문제 10986번
typedef long long ll;
ll num[1000001], sum[1000001], com[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    ll n, m, i, result = 0;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        cin >> num[i];
    }
    for(i=1;i<=n;i++){
        if(i == 0)
            sum[i] = num[i];
        else
            sum[i] = sum[i-1] + num[i];
        sum[i] %= m;
        if(sum[i] == 0)
            result++;
        com[sum[i]]++;
    }
    for(i=0;i<m;i++){
        result += com[i] * (com[i]-1) / 2;
    }
    cout << result;
}