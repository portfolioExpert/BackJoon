#include <iostream>
#include <algorithm>
using namespace std;

//문제 14648번
int main(){
    int n, num[1001], m, i, j, type, a, b, c, d;
    long long sum, sum2;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        cin >> num[i];
    }
    for(i=0;i<m;i++){
        cin >> type;
        cin >> a >> b;
        sum = 0;
        for(j=a;j<=b;j++){
            sum+=num[j];
        }
        if(type == 1){
            cout << sum << "\n";
            swap(num[a], num[b]);
        }
        else if(type == 2){
            sum2=0;
            cin >> c >> d;
            for(j=c;j<=d;j++){
                sum2+=num[j];
            }
            cout << sum - sum2 << "\n";
        }
    }
    return 0;
}