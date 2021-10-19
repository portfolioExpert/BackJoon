//문제 4792번 레드 블루 스패닝 트리 -> 최소 스패닝 트리
#include <queue>
int parent[1001];
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
int n, m, k;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    while(1){
        cin >> n >> m >> k;
        if(n == 0 && m == 0 && k == 0)
            break;
        for(int i = 1;i<=n;i++){
            parent[i] = i;
        }
        int maxval = 0, minval = 0;
        char c;
        int f, t;
        queue<pair<int,int>>rq;
        queue<pair<int,int>>bq;
        vector<pair<char,pair<int,int>>>in;
        //블루 간선의 최대치
        //블루 부터 연결하고 최대치를 계산
        for(int i = 0;i<m;i++){
            cin >> c >> f >> t;
            in.push_back({c, {f,t}});
            if(c == 'B' && find(f) != find(t)){
                merge(f, t);
                maxval++;
            }
            else
                rq.push({f, t});
        }
        while(!rq.empty()){
            int from = rq.front().first;
            int to = rq.front().second;
            rq.pop();
            if(find(from) != find(to))
                merge(from, to);
        }

        //블루간선 최소치
        //레드부터 연결하고 블루연결 후 최소값 계산
        for(int i = 1;i<=n;i++){
            parent[i] = i;
        }
        for(int i = 0;i<(int)in.size();i++){
            char c = in[i].first;
            int from = in[i].second.first;
            int to = in[i].second.second;
            if(c == 'R' && find(from) != find(to)){
                merge(from, to);
            }
            else
                bq.push({from, to});
        }
        while(!bq.empty()){
            int from = bq.front().first;
            int to = bq.front().second;
            bq.pop();
            if(find(from) != find(to)){
                merge(from, to);
                minval++;
            }
        }
        if((maxval >= k) && (k >= minval))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}