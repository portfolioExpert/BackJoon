//문제 4386번 별자리 만들기 -> 최소 스패닝 트리
#include <stdio.h>
#include <vector>
#include <cmath>
#include <queue>
priority_queue<pair<double, pair<int,int>>>pq;
vector<pair<double,double>>v;
int visit[101];
int parent[101];
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
    int n;
    double result = 0;
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        double a, b;
        scanf("%lf %lf", &a, &b);
        v.push_back({a,b});
    }
    for(int i = 0;i<n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i==j)
                continue;
            double gx = pow(abs(v[i].first - v[j].first),2);
            double gy = pow(abs(v[i].second - v[j].second),2);
            double dis = sqrt(gx + gy);
            pq.push({-dis,{i,j}});
        }
    }
    while(!pq.empty()){
        double cost = -pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        if(find(from) != find(to)){
            merge(from ,to);
            result+=cost;
        }
    }
    printf("%.2lf", result);
}