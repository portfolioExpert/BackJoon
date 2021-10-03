#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 2231번
int main(){
    int answer, i, newn = 0, save, min = 0;
    cin >> answer;
    for(i=answer;i>=0;i--){
        save = i;
        while(save){
            newn += save % 10;
            save/=10;
        }
        if(answer == i+newn){
            min = i;
        }
        newn = 0;
    }
    if(min == 0)
        cout << 0;
    else
        cout << min;
    return 0;
}