#include <iostream>
#include <algorithm>
using namespace std;

//문제 11725번
#include <vector>
vector <int> v[100001];
bool visit[100001];
int parent[100001];
void DFS(int x);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, num1, num2;
    cin >> n;
    for(i=0;i<n-1;i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    DFS(1);
    for(i=2;i<=n;i++){
        cout << parent[i] << "\n";
    }
    return 0;
}
void DFS(int x){
    visit[x] = 1;
    for(int y : v[x]){
        if(visit[y] == 0){
            parent[y] = x;
            visit[y] = 1;
            DFS(y);
        }
    }
}