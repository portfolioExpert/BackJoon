//문제 3780번 네트워크 연결 -> 유니온 파인드 응용
int parent[20001];
int dis[20001];
int find(int node){
    if(parent[node] == 0)return node;
    int val = find(parent[node]);
    //parent로 올라가면서 다 더해준다
    dis[node] += dis[parent[node]];
    //parent로 올라가면서 부모 재설정
    parent[node] = val;
    return val;
}
void merge(int node1, int node2){
    dis[node1] = abs(node1 - node2) % 1000;
    //node1센터는 node2센터에 의해 제공
    parent[node1] = node2;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        for(int j = 1;j<=n;j++){
            parent[j] = 0;
            dis[j] = 0;
        }
        while(1){
            char cm;
            int l, j;
            cin >> cm;
            if(cm == 'E'){
                cin >> l;
                //더하는 행위
                find(l);
                cout << dis[l] << "\n";
            }
            else if(cm == 'I'){
                cin >> l >> j;
                merge(l, j);
            }
            else
                break;
        }
    }
}