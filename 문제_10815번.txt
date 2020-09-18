#include <iostream>
#include <algorithm>
using namespace std;

//문제 10815번
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,i, num[500001], m, search, mid, left = 0, right, result = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    cin >>m;
    sort(num, num+n);
    for(i=0;i<m;i++){
        cin >> search;
        left = 0;
        right = n-1;
        result = 0;
        while(left <= right){
            mid = (left+right)/2;
            if(num[mid] < search){
                left = mid + 1;
            }
            else if(num[mid] > search){
                right = mid - 1;
            }
            else{
                result = 1;
                break;
            }
        }
        if(result == 0)
            cout << 0 << " ";
        else
            cout << 1 << " ";
    }
    return 0;
}