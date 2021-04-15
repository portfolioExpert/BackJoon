#include <iostream>
#include <algorithm>
using namespace std;

//문제 1707번
//이분그래프란 이어진 노드사이에 모두 다른색일 경우 즉 빨강 빨강으로 칠해진 노드가 접해있는 것은 이분그래프가 아님
#include <vector>
#include <cstring>
int visit[20001];
bool flag = 0;
void dfs(int index, vector<int> node[]);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int v, e;
        cin >> v >> e;
        vector <int> node[20001];
        flag = 0;
        memset(visit, -1, sizeof(visit));
        for(int j = 0;j<e;j++){
            int num1 , num2;
            cin >> num1 >> num2;
            node[num1].push_back(num2);
            node[num2].push_back(num1);
        }
        for(int j = 0;j<v;j++){
            if(visit[j] == -1){
                visit[j] = 1;//무조건 1부터 시작
                dfs(j, node);
            }
        }
        if(flag == 0){//이분그래프 이다
            cout << "YES" << "\n";
        }
        else
            cout << "NO" << "\n";
    }
}
void dfs(int index, vector<int> node[]){
    for(int y : node[index]){
        if(visit[y] == visit[index]){//색이 같으면 이분그래프X
            flag = 1;
            return;
        }
        if(visit[y] == -1){
            if(visit[index] == 1)
                visit[y] = 2;
            else if(visit[index] == 2)
                visit[y] = 1;
            dfs(y, node);
        }
    }
}