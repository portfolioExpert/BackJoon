#include <iostream>
#include <algorithm>
using namespace std;

//문제 2357번 
//세그먼트 트리를이용한 최대 최소
typedef long long ll;
int minnum[400010];
int maxnum[400010];
int input[100010];
struct minTree{
    int init(int left, int right, int node){
        if(left == right)return minnum[node] = input[left];
        int mid = (left+right)/2;
        return minnum[node] = min(init(left, mid, node * 2), init(mid + 1, right, node*2 + 1));
    }

    int querymin(int left, int right, int node, int nodeleft, int noderight){
        if(right < nodeleft || left > noderight)return 1000000001;
        if(left <= nodeleft && noderight <= right)return minnum[node];
        int mid = (nodeleft + noderight)/2;
        return min(querymin(left, right, node * 2, nodeleft, mid), querymin(left, right, node*2 + 1, mid + 1, noderight));
    }

};
struct maxTree{
    int init(int left, int right, int node){
        if(left == right)return maxnum[node] = input[left];
        int mid = (left+right)/2;
        return maxnum[node] = max(init(left, mid, node * 2), init(mid + 1, right, node*2 + 1));
    }

    int querymax(int left, int right, int node, int nodeleft, int noderight){
        if(right < nodeleft || left > noderight)return -1;
        if(left <= nodeleft && noderight <= right)return maxnum[node];
        int mid = (nodeleft + noderight)/2;
        return max(querymax(left, right, node * 2, nodeleft, mid), querymax(left, right, node*2 + 1, mid + 1, noderight));
    }

};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, i;
    minTree mint;
    maxTree maxt;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        cin >> input[i];
    }
    mint.init(1, n, 1);
    maxt.init(1, n, 1);
    for(i=0;i<m;i++){
        int left, right;
        cin >> left >> right;
        cout << mint.querymin(left, right, 1, 1, n) << " " << maxt.querymax(left, right, 1, 1, n) << "\n";
    }
}