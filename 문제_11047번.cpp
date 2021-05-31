#include <iostream>
#include <algorithm>
using namespace std;

//문제 11047번
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, cnt = 0, i , cash[11];
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> cash[i];
    }
    for(i=n-1;i>=0;){
        if(k >= cash[i]){
            k-=cash[i];
            cnt++;
        }
        else
            i--;
        if(k == 0)break;
    }
    cout << cnt;
    return 0;
}