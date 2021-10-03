#include <iostream>
#include <algorithm>
using namespace std;

//문제 5565번
int main(){
    int book, total, i, sum = 0;
    cin >> total;
    for(i=0;i<9;i++){
        cin >> book;
        sum+=book;
    }
    cout << total - sum;
    return 0;
}