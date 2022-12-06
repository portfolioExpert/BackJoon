#include <iostream>
#include <algorithm>
using namespace std;

//문제 10972번 다음 순열 -> 조합론, next_permutation
#include <vector>
vector<int>v;
int main(){
    int n;
    cin >> n;
    string str ="";
    bool flag= true;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    if(next_permutation(v.begin(), v.end())){
        for(int i = 0;i<n;i++){
            cout << v[i] << " ";
            flag = false;
        }
    }
    if(flag)
        cout << -1;
}