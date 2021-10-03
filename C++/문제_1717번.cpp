//문제 1717 집합의 표현 -> 유니온 파인드
int parent[1000001];
int setsize[1000001];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);

    if(node1 != node2){
        if(setsize[node1] < setsize[node2])
            swap(node1, node2);
        parent[node2] = node1;
        setsize[node1] += setsize[node2];
        setsize[node2] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<1000001;i++){
        parent[i] = i;
        setsize[i] = 1;
    }
    for(int i = 0;i<m;i++){
        int num, a, b;
        cin >> num >> a >> b;
        if(num == 0){
            merge(a, b);
        }
        if(num == 1){
            if(find(parent[a]) == find(parent[b]))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
}