#include <iostream>
#include <algorithm>
using namespace std;

//문제 10868번
int number[100010];
int tree[400010];
struct segmentTree{
    int init(int left, int right, int node){
        if(left == right)return tree[node] = number[left];
        int mid = (left + right)/2;
        return tree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node*2 + 1));
    }

    int query(int left, int right, int node, int nodeleft, int noderight){
        if(right < nodeleft || left > noderight)return 1000000001;
        if(left<=nodeleft && noderight <= right)return tree[node];
        int mid = (nodeleft + noderight)/2;
        return min(query(left, right, node*2, nodeleft, mid), query(left, right, node *2 + 1, mid + 1, noderight));
    }

};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, i;
    segmentTree t;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        cin >> number[i];
    }
    t.init(1, n, 1);
    for(i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        cout << t.query(a, b, 1, 1, n) << "\n";
    }
    return 0;
}