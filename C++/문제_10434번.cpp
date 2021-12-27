//문제 10434번 행복한 소수 ->에라토스테네스의 체, 구현
#include <cmath>
#include <cstring>
bool visit[10001];
bool ch[10001] = {1, 1, 0, };
bool happynumber(int num){
    int start = num;
    while(1){
        int next = 0;
        if(start == 1)
            return 1;
        else{
            visit[start] = 1;
            while(start){
                next += (start % 10) * (start % 10);
                start /= 10;
            }
        }
        if(visit[next] == 1)
            return false;
        start = next;
    }
    return !ch[num];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int p;
    cin >> p;
    for(int i = 2;i<=sqrt(10000);i++){
        if(ch[i] == 1)continue;
        for(int j = 2 * i;j <= 10000;j+=i){
            ch[j] = 1;
        }
    }
    for(int i = 1;i<=p;i++){
        memset(visit, 0, sizeof(visit));
        int t, num;
        cin >> t >> num;
        cout << t << " " << num << " ";
        if(happynumber(num)){
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}