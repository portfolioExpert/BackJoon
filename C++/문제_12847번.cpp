#include <iostream>
#include <algorithm>
using namespace std;

//문제 12847번 꿀 아르바이트 -> 누적 합
long long result = 0;
int num[100001];
long long prefixSum[100001];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> num[i];
    }
    for(int i = 1;i<=n;i++){
        prefixSum[i] = prefixSum[i - 1] + num[i];
    }
    for(int i = m;i<=n;i++){
        result = max(result, prefixSum[i] - prefixSum[i-m]);
    }
    cout << result;
}