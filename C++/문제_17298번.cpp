//문제 17298번 오큰수 -> 스택
#include <stack>
stack <pair<int,int>>s;
int num[1000001];
int result[1000001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
        result[i] = -1;
    }
    s.push({num[0], 0});
    for(int i = 1;i<n;i++){
        if(s.size() > 0 && s.top().first < num[i]){
            while(s.size() > 0 && num[i] > s.top().first){
                int index = s.top().second;
                s.pop();
                result[index] = num[i];
            }
            s.push({num[i], i});
        }
        else
            s.push({num[i], i});
    }
    for(int i = 0;i<n;i++){
        cout << result[i] << " ";
    }
}