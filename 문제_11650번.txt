#include <iostream>
#include <algorithm>
using namespace std;

//문제 11650번
#include <vector>
vector <pair<int,int>> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,i, num1, num2;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num1 >> num2;
        v.push_back({num1, num2});
    }
    sort(v.begin(), v.end());
    for(i=0;i<n;i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}