#include <iostream>
#include <algorithm>
using namespace std;

//문제 14646번
#include <vector>
vector <int>v;
int main(){
    int n, i, cnt = 0, num, msize = -1;
    cin >> n;
    v.assign(100001, 0);
    for(i=0;i<n*2;i++){
        cin >> num;
        if(v[num] == 0){
            v[num] = num;
            cnt++;
        }
        else if(v[num] != 0){
            cnt--;
        }
        msize = max(msize,cnt);
    }
    cout << msize;
    return 0;
}