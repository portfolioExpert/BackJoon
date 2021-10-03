#include <iostream>
#include <algorithm>
using namespace std;

//문제 1275번 -> 자료형 신경써야함
typedef long long ll;
ll number[100010];
ll tree[400010];
struct segmentTree{
    ll init(int left, int right, int node){
        if(left == right)return tree[node] = number[left];
        int mid = (left + right) / 2;
        return tree[node] = init(left, mid, node*2) + init(mid + 1, right, node*2 + 1);
    }

    ll query(int left, int right, int node, int nodeleft, int noderight){
        if(right < nodeleft || left > noderight)return 0;
        if(left <= nodeleft && noderight <= right)return tree[node];
        int mid = (nodeleft + noderight)/2;
        return query(left, right, node*2, nodeleft, mid) + query(left, right, node*2+1, mid+1, noderight);
    }

    ll update(int index, int newval, int node, int nodeleft, int noderight){
        if(index < nodeleft || index > noderight)return tree[node];
        if(nodeleft == noderight)return tree[node] = newval;
        int mid = (nodeleft + noderight) / 2;
        return tree[node] = update(index, newval, node*2, nodeleft, mid) + update(index, newval, node*2 + 1, mid + 1, noderight);
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, q, i;
    segmentTree t;
    cin >> n >> q;
    for(i=1;i<=n;i++){
        cin >> number[i];
    }
    t.init(1, n, 1);
    while(q--){
        int x, y, a ,b;
        cin >> x >> y >> a >> b;
        if(y < x){
            int tmp = y;
            y = x;
            x = tmp;
        }
        cout << t.query(x, y , 1, 1 ,n) << "\n";
        t.update(a, b, 1, 1, n);
    }
}