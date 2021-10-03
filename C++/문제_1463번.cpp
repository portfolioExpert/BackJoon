#include <iostream>
#include <algorithm>
using namespace std;

//문제 1463번 하나하나 메모리제이션
int result[1000001] = {0};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i;
    cin >> n;
    for(i = 2; i<=n;i++){
        result[i] = result[i-1] + 1;
        if(i % 2 == 0){
            result[i] = min(result[i], result[i/2]+1);
        }
        if(i % 3 == 0){
            result[i] = min(result[i], result[i/3]+1);
        }
    }
    cout << result[n];
    return 0;
}