//문제 13418번 학교 탐방하기 -> 최소 스패닝 트리(크루스칼)
#include <vector>
vector<pair<int,pair<int,int>>>v;
int parent[1001];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1 ,int node2){
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2)
        parent[node2] = node1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<m + 1;i++){
        int a, b ,c;
        cin >> a >> b >> c;
        v.push_back({-c, {a, b}});
    }
    sort(v.begin(), v.end());
    //최소의 경로
    int minval = 0;
    for(int i = 0;i<(int)v.size();i++){
        int from = v[i].second.first;
        int to = v[i].second.second;
        int cost = v[i].first;
        if(find(from) != find(to)){
            if(cost == 0)
                minval++;
            merge(from, to);
        }
    }
    //최대의 경로
    reverse(v.begin(), v.end());
    for(int i = 0;i<=n;i++){
        parent[i] = i;
    }
    int maxval = 0;
    for(int i = 0;i<(int)v.size();i++){
        int from = v[i].second.first;
        int to = v[i].second.second;
        int cost = v[i].first;
        if(find(from) != find(to)){
            if(cost == 0)
                maxval++;
            merge(from, to);
        }
    }
    cout << pow(maxval, 2) - pow(minval, 2);
}