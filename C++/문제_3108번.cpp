//문제 3108번 로고 -> 유니온 파인드
int parent[1001];
int map[1001][1001];
int find(int node){
    if(parent[node] == node)
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
    int result = 1;
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 1;i<=n;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=500;
        x2+=500;
        y1+=500;
        y2+=500;
        //x축그리기
        for(int j = x1;j<=x2;j++){
            if(map[y1][j] != 0){
                if(find(map[y1][j]) != find(i)){
                    merge(map[y1][j], i);
                    result++;
                }
            }
            if(map[y2][j] != 0){
                if(find(map[y2][j]) != find(i)){
                    merge(map[y2][j], i);
                    result++;
                }
            }
            map[y1][j] = i;
            map[y2][j] = i;
        }
        //y축 그리기
        for(int j = y1;j<=y2;j++){
            if(map[j][x1] != 0){
                if(find(map[j][x1]) != find(i)){
                    merge(map[j][x1], i);
                    result++;
                }
            }
            if(map[j][x2] != 0){
                if(find(map[j][x2]) != find(i)){
                    merge(map[j][x2], i);
                    result++;
                }
            }
            map[j][x1] = i;
            map[j][x2] = i;
        }
    }
    if(map[500][500] == 0)
        cout << n - result + 1;
    else
        cout << n - result;
}