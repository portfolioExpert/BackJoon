#include <iostream>
#include <algorithm>
using namespace std;

//문제 15886번
int main(){
    int n, i, cnt = 0;
    char load[1001];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> load[i];
    }
    for(i=0;i<n-1;i++){
        if(load[i] == 'E' && load[i+1] == 'W')
            cnt++;
    }
    cout << cnt;
    return 0;
}