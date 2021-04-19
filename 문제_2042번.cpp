#include<iostream>
#include <algorithm>
using namespace std;

//문제 2042번 세그먼트 트리 기초
typedef long long ll;
ll number[1000001];
ll tree[4000001];
struct segmentTree{
    //초기화
    ll init(int l, int r, int node){
        if(l == r)return tree[node] = number[l];
        int mid = (l + r)/2;
        ll leftmin = init(l, mid, node *2);//왼쪽
        ll rightmin = init(mid + 1, r, node *2 + 1);
        return tree[node] = leftmin + rightmin;
    }
    //질의연산 구현
    ll query(int l, int r, int node, int nodel, int noder){
        if(r < nodel || noder < l)return 0;
        if(l <= nodel && noder <= r)return tree[node];
        int mid = (nodel + noder)/2;
        return query(l, r, node *2, nodel, mid) + query(l, r, node *2 + 1, mid + 1, noder);
    }
    //해당 인덱스 부분 값 수정
    ll update(int index, int newval, int node, int nodel, int noder){
        if(index < nodel || noder < index)return tree[node];
        if(nodel == noder)return tree[node] = newval;
        int mid = (nodel + noder)/2;
        return tree[node] = update(index, newval, node*2, nodel, mid) + update(index, newval, node*2 + 1, mid + 1, noder);
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
        cin >> number[i];
    }
    t.init(1, n, 1);
    for(i=0;i<m + k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1)
            t.update(b, c, 1, 1, n);
        else if(a == 2)
            cout << t.query(b, c, 1, 1, n) << "\n";
    }
}