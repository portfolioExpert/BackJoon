#include <iostream>
#include <algorithm>
using namespace std;

//문제 1826번 연료 채우기
//L: 성경의 위치에서 마을까지 거리, P: 첫 연료
#include <queue>
#include <vector>
vector<pair<int,int>>v;
//주유소 정보를 넣는데 연료를 가장 많이 들고 있는 순으로 꺼내 먹듯이
priority_queue<int>pq;//연료를 가장 많이 들고 있는 주유소
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int a, b;
        cin >> a >> b;
        //시작에서 주유소 까지 거리, 채울 수 있는 연료 양
        v.push_back({a, b});
    }
    int l, p;
    cin >> l >> p;
    sort(v.begin(), v.end());

    int result = 0;
    for(int i = 0;i<v.size();){
        //안에 갈 수 있는 주유소 전부 넣어주고
        if(v[i].first <= p){
            pq.push(v[i].second);
            i++;
            continue;
        }
        bool flag = true;
        //연료 없을 때 꺼내 먹어요~
        while(!pq.empty() && v[i].first > p){
            p+=pq.top();
            pq.pop();
            result++;
            flag = false;
        }
        //연료를 안꺼낸 거면 더 이상 못가므로 종료
        if(flag)
            break;
    }

    //마지막까지 갈 수 있는지 체크
    while(!pq.empty() && p < l){
        p += pq.top();
        pq.pop();
        result++;
    }

    if(p < l)
        cout << -1;
    else
        cout << result;
}