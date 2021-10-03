#include <iostream>
#include <algorithm>
using namespace std;

//문제 10451번
#include <vector>
bool visit[1001];
vector <int> v[1001];
void DFS(int start);
int main(){
    int t, n, i, j, num[1001], cnt = 0;
    cin >> t;
    for(i=0;i<t;i++){
        cin >> n;
        for(j=1;j<=n;j++){
            cin >> num[j];
            v[j].push_back(num[j]);//노드에 각각 연결
        }
        for(j=1;j<=n;j++){
            if(visit[j] == 0){
                DFS(j);
                cnt++;
            }
        }
        fill_n(visit , 1001, 0);//방문 노드를 초기화
        cout << cnt <<"\n";
        cnt = 0;//테스트 케이스당 사이클 갯수가 다르므로 초기화
        for(j=1;j<=n;j++){
            v[j].clear();//연결된 노드를 각 인덱스별로 초기화
        }
    }
    return 0;
}
void DFS(int start){
    visit[start] = 1;
    for(int y : v[start]){//y값이 v안에 있는 노드를 따라 다니며 사이클을 구한다
        if(visit[y] == 0){
            visit[y] = 1;
            DFS(y);
        }
    }
}