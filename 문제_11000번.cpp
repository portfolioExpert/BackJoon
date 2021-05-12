#include <iostream>
#include <algorithm>
using namespace std;

//문제 11000번
//강의실 배정문제
#include <vector>
#include <queue>
priority_queue <int> q;
vector <pair<int, int>> v;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, num1, num2;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num1 >> num2;
        v.push_back({num1, num2});
    }
    sort(v.begin(), v.end());
    q.push(v[0].second);
    for(i=1;i<n;i++){
        if(q.top() <= v[i].first){
            q.pop();
        }
        q.push(v[i].second);
    }
    cout << q.size();
    return 0;
}