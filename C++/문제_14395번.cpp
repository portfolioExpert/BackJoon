//문제 14395번 4연산 -> BFS
typedef long long ll;
#include <set>
#include <queue>
#include <string>
#include <map>
ll s, t;
set<ll>se;
void bfs(){
    queue<pair<ll, string>>q;
    q.push({s, ""});
    se.insert(s);
    while(!q.empty()){
        ll now = q.front().first;
        string str = q.front().second;
        q.pop();
        if(now == t){
            cout << str;
            return;
        }
        if(now >= 1000000000000000000 || now <= 0)
            continue;
        if(se.count(now * now) != 1){
            se.insert(now * now);
            q.push({now * now, str+'*'});
        }
        if(se.count(now + now) != 1){
            se.insert(now + now);
            q.push({now + now, str+'+'});
        }
        if(se.count(now / now) != 1){
            se.insert(now / now);
            q.push({now / now, str+'/'});
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> s >> t;
    if(s == t){
        cout << 0;
        return 0;
    }
    if(t == 1){
        cout << "/";
        return 0;
    }
    bfs();
    if(se.find(t) == se.end())
        cout << -1;
    return 0;
}