//문제 4195번 친구 네트워크 -> 유니온 파인드
#include <map>
#include <vector>
#include <string>
#include <cstring>
int parent[200001];
int setsize[200001];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
    //루트 노드를 찾고
    node1 = find(node1);
    node2 = find(node2);

    //서로 다른집합일 경우
    if(node1 != node2){
        //큰 집합으로 작은 집합이 들어간다
        if(setsize[node1] < setsize[node2])
            swap(node1, node2);

        parent[node2] = node1;//2집합이 1 집합에 합쳐진다.
        setsize[node1] += setsize[node2];//흡수 되므로 사이즈 최신화
        setsize[node2] = 0;//흡수 되므로 0으로 초기화
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int index = 1;
        int n;
        cin >> n;
        map<string,int>m;
        //초기화
        for(int j = 0;j<100001;j++){
            parent[j] = j;
            setsize[j] = 1;
        }

        for(int j = 0;j<n;j++){
            string str1, str2;
            cin >> str1 >> str2;
            //맵 내 초기화
            if(m[str1] == 0){
                m[str1] = index++;
            }
            if(m[str2] == 0){
                m[str2] = index++;
            }

            //이름에 대한 루트를 찾는다
            int parent1 = find(m[str1]);
            int parent2 = find(m[str2]);

            //다른 집합이면 합병해주고
            if(parent1 != parent2)
                merge(parent1, parent2);

            //같으면 그냥 출력해주면 된다
            cout << max(setsize[parent1], setsize[parent2]) << "\n";
        }
    }
}