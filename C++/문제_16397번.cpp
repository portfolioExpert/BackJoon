#include <iostream>
#include <algorithm>
using namespace std;

//문제 16397번 탈출 -> BFS
//A를 누르면 1증가
//B 누르면 N에 2곱하고 0이 아닌 가장 높은 자릿수 숫자가 1 줄어든다.
//N이 99999을 넘으면 탈출 실패
//T번 눌러서 N을 G로 같게 해야한다.
#include <queue>
#include <cstring>
int visit[100001];
void bfs(int n, int t, int g){
    visit[n] = 0;
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int val = q.front();
        q.pop();

        //A클릭
        if(val + 1 < 100000 && visit[val + 1] > visit[val] + 1){
            q.push(val + 1);
            visit[val + 1] = visit[val] + 1;
        }

        //B클릭
        int save = val * 2;
        //곱했을 때 넘어가면 탈락
        if(save > 99999)
            continue;
        string next = to_string(save);
        next[0] = next[0] - 1;

        bool flag = true;
        //문자열 이상한게 없는지 검사
        for(int i = 0;i<next.size();i++){
            if(!(next[i] >= '0' && next[i] <='9')){
                flag = false;
                break;
            }
        }

        if(!flag)
            continue;

        if(visit[stoi(next)] > visit[val] + 1){
            q.push(stoi(next));
            visit[stoi(next)] = visit[val] + 1;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, t, g;
    cin >> n >> t >> g;
    fill_n(visit, 100000, 987654321);
    bfs(n, t, g);
    //t보다 크고, 방문을 못했다면 ANG
    if(t < visit[g] || visit[g] == 987654321)
        cout << "ANG";
    else
        cout << visit[g];
}