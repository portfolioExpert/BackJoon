#include <iostream>
#include <algorithm>
using namespace std;

//문제 10818번
#include <vector>
vector <int> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, num;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << v[0] << " "<< v[n-1];
    return 0;
}
