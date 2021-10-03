#include <iostream>
#include <algorithm>
using namespace std;

//문제 7510번
int main(){
    int t, i, j,arr[3];
    cin >> t;
    for(i=0;i<t;i++){
        cin >> arr[0] >> arr[1] >> arr[2];
        int high, check = 0, sum = 0;
        high = max(arr[0], max(arr[1],arr[2]));
        cout << "Scenario #" << i+1 << ":\n";
        for(j=0;j<3;j++){
            if(high != arr[j])
                sum+=arr[j] * arr[j];
        }
        if(sqrt(sum) == high)
            check = 1;
        if(check == 0){
            cout << "no" << "\n";
        }
        else
            cout << "yes" << "\n";
        cout << "\n";
    }
    return 0;
}