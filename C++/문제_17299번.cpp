//문제 17299번 오등큰수 -> 스택
#include <stack>
stack <pair<int,int>>s;
int f[1000001];
int num[1000001];
int result[1000001];
int n;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> num[i];
        result[i] = -1;
        f[num[i]]++;
    }
    s.push({num[1],1});
    for(int i = 2;i<=n;i++){
        if(s.size() > 0 && f[s.top().first] < f[num[i]]){
            while(s.size() > 0 && f[num[i]] > f[s.top().first]){
                int index = s.top().second;
                result[index] = num[i];
                s.pop();
            }
            s.push({num[i], i});
        }
        else
            s.push({num[i], i});
    }
    for(int i = 1;i<=n;i++){
        cout << result[i] << " ";
    }
}