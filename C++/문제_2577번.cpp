#include <iostream>
#include <algorithm>
using namespace std;

//문제 2577번
int main(){
    int a, b, c, result, num[10];
    fill_n(num, 10, 0);
    cin >> a >> b >> c;
    result = a * b * c;
    while(result){
        num[result % 10]++;
        result/=10;
    }
    for(int i = 0; i<10;i++){
        cout << num[i] << "\n";
    }
    return 0;
}