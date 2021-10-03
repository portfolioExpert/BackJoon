#include <iostream>
#include <algorithm>
using namespace std;

//문제 10886번
int main(){
    int n, agree = 0, no = 0, i, num;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        if(num == 1)
            agree++;
        else
            no++;
    }
    if(agree> no)
        cout << "Junhee is cute!";
    else
        cout << "Junhee is not cute!";
    return 0;
}