//문제 20040번 사이클 게임 -> 유니온 파인드
int parent[500001];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
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
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        if(find(num1) != find(num2)){
            merge(num1, num2);
            continue;
        }
        if(find(num1) == find(num2)){
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
}