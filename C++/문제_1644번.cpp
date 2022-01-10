//문제 1644번 소수의 연속합 -> 두 포인터, 에라토스테네스의 체
#include <vector>
bool visit[4000001];
vector<int>v;//소수를 담은 것
//소수 체크
void fx(int n){
    for(int i = 2;i<=n;i++){
        if(visit[i] == 1)continue;
        for(int j = i + i; j<=n;j+=i){
            visit[j] = 1;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 0;
    int n;
    cin >> n;
    fx(n);
    for(int i = 2;i<=n;i++){
        if(visit[i] == 0)
            v.push_back(i);
    }
    int sum = 0;
    int left = 0, right = 0;
    while(left <= right){
        if(sum >= n){
            sum-=v[left++];
        }
        else if(right == v.size())
            break;
        else if(sum < n)
            sum+=v[right++];
        if(sum == n)
            result++;
    }
    cout << result;
    return 0;
}