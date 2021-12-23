//문제 2961번 도영이가 만든 맛있는 음식 -> 백트래킹
#include <cmath>
bool visit[11];
int food[11][2];
int result, n;
void dfs(int index, int left, int right){
    if(index == n){
        result = min(abs(left - right), result);
        return;
    }
    for(int i = index;i<n;i++){
        dfs(i + 1, left * food[i][0], right + food[i][1]);
        dfs(i + 1, left , right);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> food[i][0] >> food[i][1];
    }
    result = abs(food[0][0] - food[0][1]);
    for(int i = 0;i<n;i++){
        dfs(i + 1, food[i][0], food[i][1]);
    }
    cout << result;
}