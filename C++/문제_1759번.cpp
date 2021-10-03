#include <iostream>
#include <algorithm>
using namespace std;

//문제 1759번
char ch[15], print[15];
int n, m;
void dfs(int now, int cnt);
int main(){
    int i;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> ch[i];
    }
    sort(ch, ch+m);
    dfs(0, 0);
    return 0;
}
void dfs(int now, int cnt){
    if(cnt == n){
        int ae = 0, notae = 0;
        bool ok = false;
        for(int i=0;i<n;i++){
            if(print[i] == 'a' || print[i] == 'e' || print[i] == 'i' || print[i] == 'u' || print[i] == 'o')
                ae++;
            else
                notae++;
        }
        if(ae >= 1 && notae >=2)
            ok = true;
        if(ok){
            for(int i = 0;i<n;i++){
                cout << print[i];
            }
            cout << "\n";
        }
        return;
    }
    for(int i = now; i<m;i++){
        print[cnt] = ch[i];
        dfs(i+1, cnt+1);
    }
}