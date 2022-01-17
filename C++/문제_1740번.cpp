//문제 1740번 거듭제곱 -> 수학
//웍스 1번
typedef long long ll;
#include <string>
int main(){
    ll n;
    string str = "";
    cin >> n;
    while(n){
        str+=(n % 2) + 48;
        n/=2;
    }
    ll result = 0;
    for(int i = 0;i<str.size();i++){
        if(str[i] == '1'){
            ll sum = 1;
            for(int j = 0;j<i;j++){
                sum*=3;
            }
            result += sum;
        }
    }
    cout << result;
}