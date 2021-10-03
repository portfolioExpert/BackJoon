#include <iostream>
#include <algorithm>
using namespace std;


//문제 1085번
int main(){
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min(w-x,min(h-y,min(x, y)));
    return 0;
}