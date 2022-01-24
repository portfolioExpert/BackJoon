//문제 1158 요세푸스 문제 -> 큐
#include <queue>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, k, cnt = 1;
    queue<int>q;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        q.push(i + 1);
    }
    cout << "<";
    while(q.size() > 1){
        int now = q.front();
        q.pop();
        if(cnt == k){
            cout << now << ", ";
            cnt = 0;
        }
        else
            q.push(now);
        cnt++;
    }
    cout << q.front() << ">";
}