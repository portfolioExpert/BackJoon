#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 1120번
int solve(string x, string y);
int main(){
    string a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}
int solve(string x, string y){
    int i, other, j;
    other = 10000;
    for(i=0;i<=y.size() - x.size();i++){
        int cnt = 0;
        for(j=0;j<x.size();j++){
            if(x[j] != y[j+i])cnt++;
        }
        other = min(other, cnt);
    }
    return other;
}