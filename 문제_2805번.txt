#include <iostream>
#include <algorithm>
using namespace std;

//문제 2805번
typedef long long ll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, m, tree[1000001], i, left = 0, right, big = -1, mid, total, result = 0;
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> tree[i];
        big = max(tree[i], big);
    }
    right = big;
    while(left <= right){
        mid = (left+right) / 2;//가장큰 값과, 0의 중간값을 찾고
        total = 0;
        for(i = 0; i<n;i++){
            if(tree[i] > mid)
                total+= tree[i]-mid; //
        }
        if(total >= m){
            if(result < mid)
                result = mid;
            left = mid+1;
        }
        else{
            right = mid - 1;
        }
    }
    cout <<result;
    return 0;
}