#include <iostream>
#include <algorithm>
using namespace std;

//문제 11004번
#include <vector>
vector <int> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int i,n, k, num;
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << v[k-1];
    return 0;
}