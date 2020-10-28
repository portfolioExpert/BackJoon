#include <iostream>
#include <algorithm>
using namespace std;

//문제 11505번
typedef long long ll;
ll number[1000100];
ll tree[4000100];
struct segmentTree{
     ll init(int left, int right, int node){
        if(left == right)return tree[node] = number[left];
        int mid = (left + right)/2;
        return tree[node] = (init(left, mid, node*2) * init(mid + 1, right, node * 2 + 1)) % 1000000007;
    }

    ll query(int left, int right, int node, int nodeleft, int noderight){
        if(right < nodeleft || left > noderight)return 1;
        if(left <= nodeleft && noderight <= right)
            return tree[node];
        int mid = (nodeleft + noderight)/2;
        return (query(left, right, node * 2, nodeleft, mid) * query(left, right, node * 2 + 1, mid + 1, noderight)) % 1000000007;
    }

    ll update(int index, int newval, int node, int nodeleft, int noderight){
        if(index < nodeleft || noderight < index)return tree[node];
        if(nodeleft == noderight)return tree[node] = newval;
        int mid = (nodeleft + noderight)/2;
        return tree[node] = (update(index, newval, node*2, nodeleft, mid) * update(index, newval, node*2 + 1, mid + 1, noderight)) % 1000000007;
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, k, i;
    segmentTree t;
    cin >> n >> m >> k;
    for(i=1;i<=n;i++){
        cin >>number[i];
    }
    t.init(1, n, 1);
    for(i = 0;i<m + k;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            t.update(b, c, 1, 1, n);
        }
        else{
            cout << t.query(b, c, 1, 1, n) << "\n";
        }
    }
}