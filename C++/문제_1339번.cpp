#include <iostream>
#include <algorithm>
using namespace std;

//문제 1339번
#include <string>
int al[26], cal = 9, result;
string str[11];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, i, j;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> str[i];
    }
    for(i=0;i<n;i++){
        int t = (int)str[i].size() - 1;
        for(j=0;j<str[i].size();j++){
            al[str[i][j] - 'A'] += pow(10, t);
            t--;
        }
    }
    sort(al, al + 26);
    reverse(al, al+26);
    for(i=0;i<10;i++){
        result+=al[i] * cal;
        cal--;
    }
    cout << result;
}