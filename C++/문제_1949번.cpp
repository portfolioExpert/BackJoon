#include <iostream>
#include <algorithm>
using namespace std;

//문제 1949번
#include <vector>
bool visit[10001];
int value[10001];
vector <int> v[10001];
int dfs(int x, int flag);
int main(){
    int n, i, num1, num2;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> value[i];
    }
    for(i=0;i<n-1;i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    cout << max(dfs(1,0), dfs(1,1) + value[1]);//1이 우수마을인지 아닌지를 결정후 그래프로 돌면서 최대를 구한다
    return 0;
}
int dfs(int x, int flag){
    int result = 0;
    visit[x] = 1;
    for(int y : v[x]){
        if(visit[y] == 0){
            if(flag){
                result+=dfs(y, 0);//반환 값이 result이므로 자체 dp를 형성
            }
            else{
                result+=max(dfs(y, 0), dfs(y, 1) + value[y]);
            }
        }
    }
    visit[x] = 0;//재귀함수 이용하므로 방문 했던 곳을 재 방문 해야하므로 주기적으로 초기화
    return result;
}