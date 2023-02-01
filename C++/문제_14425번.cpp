#include <iostream>
#include <algorithm>
using namespace std;

//문제 14425번 문자열 집합 -> set, map
#include <set>
set<string>s;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        s.insert(str);
    }
    int result = 0;
    for(int i = 0;i<m;i++){
        string str;
        cin >> str;
        if(s.count(str) > 0)
            result++;
    }
    cout << result;
