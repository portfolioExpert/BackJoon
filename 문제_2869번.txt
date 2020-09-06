#include <iostream>
#include <algorithm>
using namespace std;

//문제 2869번
int main(){
    int a, b, v, result;
    cin >> a >> b >> v;
    result = (v-a) / (a-b); // result 만큼 가면 다음날 도착
    if((v-a) % (b - a) != 0)result++;//딱 맞는 경우엔 안더해줌
    cout << result+1;//마지막날 도착 하루를 더해줌
    return 0;
}