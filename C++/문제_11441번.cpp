#include <iostream>
#include <algorithm>
using namespace std;

//문제 11441번
int num[100001], sum[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, i;
    cin >> n;
    for(i = 1; i<=n;i++){
        cin >> num[i];
    }
    cin >> m;
    for(i=1;i<=n;i++){
        if(i == 0)
            sum[i] = num[i];
        else
            sum[i] = sum[i-1] + num[i];
    }
    for(i=0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        cout << sum[num2] - sum[num1 - 1] << "\n";
    }
}