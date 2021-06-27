//문제 5052번
#include <vector>
#include <map>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t, i, j;
    cin >> t;
    while(t--){
        map<string, int> m;
        bool flag = 1;
        int n;
        cin >> n;
        vector<string>v;
        for(i = 0;i<n;i++){
            string str;
            cin >> str;
            v.push_back(str);
            m[str] = i+1;
        }
        for(i = 0;i<n;i++){
            string str = "";
            for(j = 0;j<(int)v[i].size() - 1;j++){
                str+=v[i][j];
                if(m[str] != 0){
                    cout << "NO" << "\n";
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
        }
        if(flag)
            cout << "YES" << "\n";
    }
}