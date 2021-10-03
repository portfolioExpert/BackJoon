#include <iostream>
#include <algorithm>
using namespace std;

//문제 7469번
#include <vector>
vector <pair<int,int>> v;
void q(int x, int y, int z);
int main(){
    int n, m, i, input1, input2, input3, num;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        cin >> num;
        v.push_back(pair<int, int> (num, i));
    }
    sort(v.begin(), v.end());
    for(i=0;i<m;i++){
        cin >> input1 >> input2 >> input3;
        q(input1, input2, input3);
    }
}
void q(int x, int y, int z){
    int i, cnt = 0;
    for(i=0;;i++){
        if(v[i].second >= x && v[i].second <= y)cnt++;
        if(cnt == z){
            cout << v[i].first << "\n";
            break;
        }
    }
}