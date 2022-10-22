//문제 2463번 비용 -> 유니온 파인드
#include <queue>
priority_queue<pair<int,pair<int,int>>>firstPQ;
int parent[100001];
long long len[100001];
long long total;//전체 가중치
long long result;
int find(int node){
    if(parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2){
        len[node1] += len[node2];
        parent[node2] = node1;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
        len[i] = 1;
    }
    for(int i = 0;i<m;i++){
        int x, y, w;
        cin >> x >> y >> w;
        total+=w;
        firstPQ.push({w,{x,y}});
    }
    while(!firstPQ.empty()){
        int cost = firstPQ.top().first;
        int node1 = find(firstPQ.top().second.first);
        int node2 = find(firstPQ.top().second.second);
        firstPQ.pop();

        //다른 집합이면
        if(node1!=node2){
            //이부분을 생각하기 어렵다.
            //현재 각 집합의 크기 * 다른 집합의 크기가 구할 수 있는 경우의 수라는 것
            //Cost(u, v)는 최소 간선부터 제거하면서 u,v가 다른 컴포넌트까지 제거되는 간선의 합
            result+=(((len[node1] * len[node2]) % 1000000000) * total) % 1000000000;
            result %= 1000000000;
            merge(node1, node2);
        }
        total-=cost;
    }
    cout << result;
}