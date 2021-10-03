//문제 3665번 최종 순위 -> 위상정렬 응용
// ?를 출력하는 것은 이미 순위가 처음부터 정해져있으므로 출력 될 수 없다.
#include <queue>
#include <vector>
#include <cstring>
bool visit[501][501];//visit는 5가 가장 순위가 높다면 [5][4] = 1,[5][3] = 1 .. 이런식으로 저장된다
int trank[501];
int in[501];
int n, m;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        queue<int>q;
        memset(visit, 0, sizeof(visit));
        memset(in, 0 , sizeof(in));
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> trank[i];
        }
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                visit[trank[i]][trank[j]] = 1;
                in[trank[j]]++;
            }
        }
        cin >> m;
        for(int i = 0;i<m;i++){
            int num1, num2;
            cin >> num1 >> num2;
            //원래 num1이 num2보다 앞일 경우
            if(visit[num1][num2]){
                visit[num1][num2] = 0;
                visit[num2][num1] = 1;
                in[num2]--;
                in[num1]++;
            }
            //원래 num2가 num1보다 앞일 경우
            else{
                visit[num1][num2] = 1;
                visit[num2][num1] = 0;
                in[num1]--;
                in[num2]++;
            }
        }
        for(int i = 1;i<=n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        vector<int>v;
        while(!q.empty()){
            int go = q.front();
            q.pop();
            v.push_back(go);
            in[go]--;
            for(int i = 1;i<=n;i++){
                if(visit[go][i]){
                    in[i]--;
                    if(in[i]==0)
                        q.push(i);
                }
            }
        }
        if(v.size() == n){
            for(int y : v)
                cout << y << " ";
        }
        else
            cout << "IMPOSSIBLE";
        cout << "\n";
    }
}