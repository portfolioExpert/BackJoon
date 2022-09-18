#include <iostream>
#include <algorithm>
using namespace std;

//문제 1676번 팩토리얼 0의 개수 -> 수학
//10은 2 * 5 따라서 곱하는 것의 2는 짝수의 개수이므로 더 많을 것이고 5의 개수만 세어주면 된다.
int main(){
    int n, result = 0;
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    for(int i = 1;i<=n;i++){
        if(i % 125 == 0)
            result+=3;
        else if(i % 25 == 0)
            result+=2;
        else if(i % 5 == 0)
            result++;
    }
    cout << result;
}