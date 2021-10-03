//문제 10775번 공항 -> 유니온 파인드
int parent[100001];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);
    parent[node1] = node2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int g,p;
    int cnt = 0;
    cin >> g >> p;
    for(int i = 1;i<=g;i++){
        parent[i] = i;
    }
    for(int i = 0;i<p;i++){
        int dock;
        cin >> dock;
        int parentnode = find(dock);
        //부모를 찾고 0에 도달하면 들어갈 곳이 없는 것
        if(parentnode != 0){
            merge(parentnode, parentnode - 1);
            cnt++;
        }
        else
            break;
    }
    cout << cnt;
}