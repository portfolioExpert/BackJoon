#include <iostream>
#include <algorithm>
using namespace std;

//문제 14494번
typedef long long ll;
int main(){
    int n, m, i, j;
    ll num[1001][1001];
    for(i=1;i<=1000;i++){
        num[1][i] = 1;
        num[i][1] = 1;
    }
    cin >> n >> m;
    for(i=2;i<=n;i++){
        for(j=2;j<=m;j++){
            num[i][j] = (num[i-1][j] + num[i][j-1] + num[i-1][j-1]) % 1000000007;
        }
    }
    cout << num[n][m];
    return 0;
}