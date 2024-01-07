#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>
typedef struct info{
    int p, f, s, v, c;
}info;
vector<info>v;
int mp, mf, ms, mv;
int n;
int result = 987654321;
vector<int>infov;
void dfs(int index, int sum, info totalinfo, vector<int>vt){
    if(result > sum && totalinfo.p >= mp && totalinfo.f >= mf && totalinfo.s >= ms && totalinfo.v >= mv){
        result = min(result, sum);
        infov = vt;
        return;
    }
    if(index == n){
        return;
    }
    for(int i = index;i<n;i++){
        totalinfo.p += v[i].p;
        totalinfo.f += v[i].f;
        totalinfo.s += v[i].s;
        totalinfo.v += v[i].v;
        totalinfo.c += v[i].c;
        sum += v[i].c;
        vt.push_back(i);
        dfs(i + 1, sum, totalinfo, vt);
        totalinfo.p -= v[i].p;
        totalinfo.f -= v[i].f;
        totalinfo.s -= v[i].s;
        totalinfo.v -= v[i].v;
        totalinfo.c -= v[i].c;
        sum -= v[i].c;
        vt.pop_back();
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0;i<n;i++){
        info inf;
        cin >> inf.p >> inf.f >> inf.s >> inf.v >> inf.c;
        v.push_back(inf);
    }
    vector<int>startv;
    info startin;
    startin.p = 0;
    startin.f = 0;
    startin.s = 0;
    startin.v = 0;
    startin.c = 0;
    dfs(0, 0, startin, startv);
    if(result == 987654321){
        cout << -1;
        return 0;
    }
    cout << result << "\n";
    for(int i = 0;i<infov.size();i++){
        cout << infov[i] + 1 << " ";
    }
}