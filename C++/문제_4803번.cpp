//문제 4803번 트리 -> 유니온 파인드
int parent[600];
bool visit[600];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);
    //둘 중 하나라도 0이면 여기서 계속 오류남
    if(node1==node2 || ((!visit[node1]) || (!visit[node2]))){
        visit[node1] = 0;
        visit[node2] = 0;
    }
    parent[node2] = node1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n,m, i = 1;
    while(1){
        cin >> n >> m;
        int result = 0;
        if(n == 0 && m == 0)break;
        for(int j = 1;j<=n;j++){
            parent[j] = j;
            visit[j] = 1;
        }
        for(int j = 0;j<m;j++){
            int num1 ,num2;
            cin >> num1 >> num2;
            merge(num1, num2);
        }
        for(int j = 1;j<=n;j++){
            int root = find(j);
            if(visit[root]){
                visit[root] = 0;
                result++;
            }
        }
        cout << "Case " << i++ << ": ";
        if(result == 1)
            cout << "There is one tree.\n";
        else if(result == 0)
            cout << "No trees.\n";
        else
            cout << "A forest of " << result << " trees.\n";
    }
}