#include <iostream>
#include <algorithm>
using namespace std;

//문제 1476번
int main(){
    int e, s ,m, year=1, first=1, second=1, third=1;
    cin >> e >> s >> m;
    while(1){
        if(first == e && second == s && third == m)break;
        else{
            (first %= 15)++;
            (second %= 28)++;
            (third %= 19)++;
        }
        year++;
    }
    cout << year;
    return 0;
}