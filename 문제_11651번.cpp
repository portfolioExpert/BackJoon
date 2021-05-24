#include <iostream>
#include <algorithm>
using namespace std;

//문제 11651번 2차원 벡터 y값 오름차순, x값 오름차순 정렬
#include <vector>
vector <pair<int, int>>v;
int main(){
    int n, i, x, y;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x >> y;
        v.push_back(pair<int, int> (y, x));
    }
    sort(v.begin(), v.end());
    for(i=0;i<n;i++){
        cout << v[i].second << " " << v[i].first << "\n";
    }
    return 0;
}