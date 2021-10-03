#include <iostream>
#include <algorithm>
using namespace std;

//문제 1939번
#include <vector>
vector<pair<int, int>> v[10001];
bool visit[10001];
int result, to;
bool dfs(int from, int weight);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, i, from, num1, num2, weight, left = 0, right = 0, mid;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> num1 >> num2 >> weight;
        v[num1].push_back({num2, weight});
        v[num2].push_back({num1, weight});
        right = max(right, weight);
    }
    cin >> from >> to;
    while(left<=right){
        mid = (left + right)/2;//mid를 최대중량으로 정한다
        if(dfs(from, mid)){
            result = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
        fill_n(visit,10001, 0);//dfs가 목적지까지 갔을때마다 방문 초기화
    }
    cout << result;
}
bool dfs(int from, int weight){
    visit[from] = 1;
    if(from == to)return true;//도착하면 트루
    for(auto y : v[from]){
        if(visit[y.first] == 0 && weight <= y.second){//mid값이 최대중량보다 작을경우
            if(dfs(y.first,weight)){//도착을 했을경우
                return 1;
            }
            else//아니면 계속 돌린다
                continue;
        }
    }
    return 0;
}