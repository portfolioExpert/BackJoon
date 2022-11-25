#include <iostream>
#include <algorithm>
using namespace std;

//문제 2303번 숫자 게임 -> 브루트 포스
#include <vector>
int result = 0;
int answer = 0;
int number = 0;
void dfs(vector<int>v, int index, int cnt, int sum){
    if(cnt == 3){
        result = max(result, sum % 10);
        return;
    }
    for(int i = index;i<5;i++){
        dfs(v, i + 1, cnt + 1, sum + v[i]);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        vector<int>v;
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        v.push_back(e);
        dfs(v, 0, 0, 0);
        if(result >= answer){
            answer = result;
            number = i + 1;
        }
        result = 0;
    }
    cout << number;
}