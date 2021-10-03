#include <iostream>
#include <algorithm>
using namespace std;

//문제 2839번
int main(){
    int n, i, array[5000] = {0, 0, 0, 1, -1, 1, 2, -1, 2, 3, 2, 3, 4, 3, 4, 3};
    cin >> n;
    for(i=16;i<=n;i++){
        array[i] = min(array[i-3], array[i-5]) + 1;
    }
    cout << array[n];
    return 0;
}