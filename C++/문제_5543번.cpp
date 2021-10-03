#include <iostream>
#include <algorithm>
using namespace std;

//문제 5543번
int main(){
    int b1, b2, b3, co, si;
    cin >> b1 >> b2 >> b3 >> co >> si;
    cout << min(b3,min(b1,b2)) + min(co, si) - 50;
}