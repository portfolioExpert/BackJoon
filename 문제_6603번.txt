#include <iostream>
#include <algorithm>
using namespace std;

//문제 6603번
int visit[6];
void dfs(int x,int y);
int cnt, num[14], t;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i;
    while(1){
        cin >> t;
        if(t == 0)break;
        for(i=0;i<t;i++){
            cin >>num[i];
        }
        dfs(0, 0);
        cout << "\n";
    }
    return 0;
}
void dfs(int x,int y){
    if(y == 6){
        for(int i=0;i<6;i++){
            cout << visit[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=x;i<t;i++){
        visit[y] = num[i];
        dfs(i + 1, y + 1);
    }
}