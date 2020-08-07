#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 2875번
int main(){
    int woman, man, inturn, team = 0;
    cin >> woman >> man >> inturn;
    while(1){
        if((woman >= 2 && man>=1) && (woman - 2 + man - 1) >= inturn){
            woman = woman-2;
            man--;
            team++;
        }
        else
            break;
    }
    cout << team;
    return 0;
}