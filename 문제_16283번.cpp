#include <iostream>
#include <algorihtm>
using namespace std;

//문제 16283번
int main(){
    int a, b,n , w, i, result1 = 0, result2 = 0, cnt = 0;
    cin >> a >> b >> n >> w;
    for(i=1;i<=n-1;i++){
        if(a * i + b * (n- i) == w){
            cnt++;
            result1 = i;
            result2 = n-i;
        }
    }
    if(cnt == 1)
        cout << result1 << " " << result2;
    else
        cout << -1;
    return 0;
}