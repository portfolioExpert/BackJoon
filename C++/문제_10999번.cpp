#include <iostream>
#include <algorithm>
using namespace std;

//문제 10999번
typedef long long ll;
ll num[1000001];
ll tree[4000001];
ll lazy[4000001];
struct segmentTree{
    ll init(int left, int right, int node){
        if(left == right)return tree[node] = num[left];
        int mid = (left + right)/2;
        return tree[node] = init(left, mid, node*2) + init(mid + 1, right, node*2 + 1);
    }

    void lazyUpdate(int node, int from, int to){
        //lazy propagation 부분으로 해당 인덱스에 더하는 부분
        if(lazy[node] != 0){
            tree[node] += (to - from + 1) * lazy[node];
            if(from != to){
                lazy[node*2] += lazy[node];
                lazy[node*2 + 1]+=lazy[node];
            }
            lazy[node] = 0;
        }
    }

    ll query(int left, int right, int node, int nodeleft, int noderight){
        //이걸 해줘야한다
        lazyUpdate(node, nodeleft, noderight);

        if(right < nodeleft || left > noderight)return 0;
        if(left<=nodeleft && noderight<=right)return tree[node];
        int mid = (nodeleft + noderight)/2;
        return query(left, right, node*2, nodeleft, mid) + query(left, right, node*2 + 1, mid + 1, noderight);
    }

    ll update(int from, int to, ll number, int node, int nodeleft, int noderight){
        lazyUpdate(node, from, to);
        if(nodeleft > to || from > noderight)return tree[node];
        if(nodeleft <= from && to <= noderight){
            tree[node] += number * (to - from + 1);
            if(from != to){
                lazy[node*2] += number;
                lazy[node*2 + 1] += number;
            }
            return tree[node];
        }
        int mid = (from + to) / 2;
        return tree[node] = update(from, mid, number, node*2, nodeleft, noderight) + update(mid + 1, to, number, node*2 + 1, nodeleft, noderight);
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n ,m, k;
    segmentTree t;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> num[i];
    }
    t.init(1, n, 1);
    for(int i = 0;i<m + k;i++){
        int a, b ,c, d;
        cin >> a >> b >> c;
        if(a == 1){
            cin >> d;
            t.update(1, n ,d, 1, b, c);
        }
        else{
            cout << t.query(b, c, 1, 1, n) << "\n";
        }
    }
}