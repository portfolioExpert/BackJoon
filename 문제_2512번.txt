#include <iostream>
#include <algorithm>
using namespace std;

//문제 2512번
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, num[10001], total, left = 0, right = 0 , mid,result = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
        right = max(num[i], right);
    }
    cin >> total;
    while(left <= right){
        int sum = 0;
        mid = (left+right)/2;
        for(i=0;i<n;i++){
            if(mid >= num[i])
                sum+=num[i];
            else
                sum+= mid;
        }
        if(sum > total)
            right = mid - 1;
        else{
            left = mid + 1;
            result = mid;
        }
    }
    cout << result;
    return 0;
}