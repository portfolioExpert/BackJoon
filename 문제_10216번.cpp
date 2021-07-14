//문제 10216번 Count Circle Group -> 유니온 파인드
#include <cmath>
#include <vector>
#include <cstring>
int parent[3001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0 ,1, -1};
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2){
        parent[node2] = node1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        int result = 0;
        vector<pair<pair<int,int>, int>>v;
        for(int i = 0;i<3001;i++){
            parent[i] = i;
        }
        for(int j = 0;j<n;j++){
            int x, y, r;
            cin >> x >> y >> r;
            v.push_back({{x ,y}, r});
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                int gox = v[i].first.first;
                int goy = v[i].first.second;
                int dis1 = v[i].second;
                int gx = v[j].first.first;
                int gy = v[j].first.second;
                int dis2 = v[j].second;
                if((gox - gx) * (gox - gx) + (goy - gy) * (goy - gy) <= (dis1 + dis2) * (dis1 + dis2)){
                    merge(i, j);
                }
            }
        }
        bool visit[3001];
        memset(visit, 0, sizeof(visit));
        for(int i = 0;i<n;i++){
            int par = find(i);
            if(visit[par] == 0){
                visit[par] = 1;
                result++;
            }
        }
        cout << result << "\n";
    }
}