#include <iostream>
#include <algorithm>
using namespace std;

//문제 4153번
typedef long long ll;
bool fx(int x[]);
int main(){
    int num[3];
    while(1){
        for(int i= 0;i<3;i++){
            cin >> num[i];
        }
        if(num[0] == 0 && num[1] == 0 && num[2] == 0)return 0;
        if(fx(num))
            cout << "right";
        else
            cout << "wrong";
        cout << "\n";
    }
}
bool fx(int x[]){
    bool ok = false;
    int big = 0;
    ll sum = 0;
    for(int i=0;i<3;i++){
        big = max(big,x[i]);
    }
    for(int i = 0;i<3;i++){
        if(big != x[i])
            sum+= x[i] * x[i];
    }
    if(big * big == sum)
        ok = true;
    return ok;
}