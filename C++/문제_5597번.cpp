#include <iostream>
#include <algorithm>
using namespace std;

//문제 5597번
int main(){
    int i, arr[31] = {0}, num;
    for(i=0;i<28;i++){
        cin >> num;
        arr[num] = 1;
    }
    for(i=1;i<=30;i++){
        if(arr[i] == 0)
            cout << i << "\n";
    }
    return 0;
}