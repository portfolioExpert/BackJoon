#include <iostream>
#include <algorithm>
using namespace std;

//문제 1781번 컵라면 -> 우선순위 큐, 그리디
//데드라인이 같은경우엔 최대로 주는 컵라면을 선택해야한다.
#include <vector>
#include <queue>
int main(){
    vector<pair<int,int>>v;
    //지금까지 얻은 컵라면 수를 넣어주는 것
    //min힙으로 가야 적은 컵라면을 빼준다.
    priority_queue<int, vector<int>, greater<int>>pq;//min힙으로 가야 적은 컵라면 수를 빼준다.
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int dead, cup;
        cin >> dead >> cup;
        v.push_back({dead, cup});
    }
    sort(v.begin(), v.end());
    int result = 0;
    for(int i = 0;i<v.size();i++){
        pq.push(v[i].second);
        //같은 데드라인을 모두 넣었다면
        while(pq.size() > v[i].first){
            pq.pop();
        }
    }
    while(!pq.empty()){
        result+=pq.top();
        pq.pop();
    }
    cout << result;
}