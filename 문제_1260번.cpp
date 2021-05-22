#include <iostream>
#include <algorithm>
using namespace std;

//문제 1260번 BFS,DFS
#include <queue>
#include <vector>
bool visit[1001];
vector <int> v[1001];
queue <int> q;
void DFS(int x);
void BFS(int k);
int main(){
    int n, m , start, i, num1, num2;
    cin >> n >> m >> start;
    for(i=0;i<m;i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);//노드간 연결 벡터 인덱스에 연결 된 노드가 저장됨
        v[num2].push_back(num1);//노드간 연결
    }
    for(i=1;i<=n;i++){//정점이 1부터 시작하므로
        sort(v[i].begin(),v[i].end());//작은것 부터 방문하기 위해 각 정점에 인접 노드를 정렬
    }
    DFS(start);
    cout << "\n";
    fill_n(visit,1001, 0);//방문 노드 초기화 시켜줌
    BFS(start);
    return 0;
}
void DFS(int x){//깊이 우선 탐색 재귀를 이용
    visit[x] = 1;//방문한 곳 체크
    cout << x << " ";//현재 방문한 곳을 출력
    for(int y : v[x]){//y는 v[1]부터 시작하여 방문하지 않은 인접 노드들을 돈다
        if(visit[y] == 0){//방문하지 않았으면 방문하기 위해 재귀, 재귀를 이용하는 이유는 지금까지 방문 한 노드를 가지고 쭉 깊은 노드까지 가기 위해서
            DFS(y);
        }
    }
}
void BFS(int k){//너비 우선 탐색 큐를 이용
    q.push(k);//정점을 작은 것 부터 q에 담는다
    visit[k] = 1;//방문한 곳 체크
    while(!q.empty()){//q가 비어있을 때 까지 돌린다
        int x = q.front();//앞에 있는 정점부터 탐색
        q.pop();//앞에 있는 것 부터 꺼낸다
        cout << x << " ";
        for(int y : v[x]){//y는 v[1]부터 시작하여 방문하지 않은 인접 노드들을 돈다
            if(visit[y] == 0){
                q.push(y);//큐에 인접 노드를 쌓는 이유는 방문 표시를 하고 큐에 넣는다.
                visit[y] = 1;
            }
        }
    }
}