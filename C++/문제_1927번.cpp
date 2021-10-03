#include <iostream>
#include <algorithm>
using namespace std;

//문제 1927번
#include <queue>
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, num;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        if(num != 0)
            pq.push(num);
        else{
            if(pq.empty() == 1)cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    return 0;
}