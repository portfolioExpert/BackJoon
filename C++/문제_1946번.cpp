//문제 1946번 신입 사원 -> 정렬
#include <vector>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        vector<pair<int,int>>v;
        for(int i = 0;i<n;i++){
            int first, second;
            cin >> first >> second;
            v.push_back({first, second});
        }
        sort(v.begin(), v.end());
        int minval = v[0].second;
        int result = 0;
        for(int i = 0;i<n;i++){
            if(minval >= v[i].second){
                result++;
                minval = v[i].second;
            }
        }
        cout << result << "\n";
    }
}