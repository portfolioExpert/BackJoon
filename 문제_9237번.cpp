#include <iostream>
#include <algorithm>
using namespace std;

//문제 9237번
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tree[100001], n, i, day = - 1;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> tree[i];
    }
    sort(tree+1, tree+n+1);
    reverse(tree+1, tree+n+1);
    for(i=1;i<=n;i++){
        if(i + tree[i] > day)
            day = (i + tree[i]);
    }
    cout << day + 1;
    return 0;
}