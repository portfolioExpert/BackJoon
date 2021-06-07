//문제 11657번
//벨만포드 문제
//음수 사이클이 존재할 경우 계속 음수로 판단하여 한도끝도없이 작아지는 것을 보존하기 위해서는 ll으로 씌워줘야 값이 커버가 된다.
typedef long long ll;
#include <vector>
vector<pair<int,ll>>v[501];
ll dis[501];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    bool flag = 0;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int num1, num2, val;
        cin >> num1 >> num2 >> val;
        v[num1].push_back({num2, val});
    }
    fill_n(dis, 501, 9999999999999);
    dis[1] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 0;k<v[j].size();k++){
                int there = v[j][k].first;
                ll cost = v[j][k].second;
                if(dis[j] != 9999999999999 && j != there && dis[there] > cost + dis[j]){
                    dis[there] = cost + dis[j];
                    //무한 사이클 일때
                    if(i == n){
                        flag = 1;
                    }
                }
            }
        }
    }
    if(flag == 1)
        cout << -1 << "\n";
    else{
        for(int i = 2;i<=n;i++){
            if(dis[i] != 9999999999999)
                cout << dis[i] << "\n";
            else
                cout << -1 << "\n";
        }
    }
}