//문제 1865번 벨만포드
#include <vector>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n ,m ,w;
        cin >> n >> m >> w;
        vector<pair<int,int>>node[501];
        int dis[501];
        bool flag = 0;
        for(int i = 0;i<m + w;i++){
            int num1, num2, val;
            cin >> num1 >> num2 >> val;
            if(i < m){
                node[num1].push_back({num2, val});
                node[num2].push_back({num1, val});
            }
            else
                node[num1].push_back({num2, -val});
        }
        for(int i =1;i<=n;i++){
            dis[i] = 987654321;
        }
        dis[1] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                for(int k = 0;k<node[j].size();k++){
                    int there = node[j][k].first;
                    int cost = node[j][k].second;
                    if(dis[there] > dis[j] + cost){
                        dis[there] = dis[j] + cost;
                        if(i == n){
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(flag)//음수사이클이 있으면 시간이 줄어들어 감소하므로 YES
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}