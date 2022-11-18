#include <iostream>
#include <algorithm>
using namespace std;

//문제 2559번 순열 -> 누적 합
int presum[100001];
int num[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int result = -101;
    for(int i = 1;i<=n;i++){
        cin >> num[i];
        presum[i] = presum[i-1] + num[i];
    }
    for(int i = k;i<=n;i++){
        result = max(result, presum[i] - presum[i - k]);
    }
    cout << result;
}