//문제 15954번 인형들 -> 브루트포스
#include <cmath>
int num[501];
double result = 987654321;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> num[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = k;j<=n;j++){
            if(j + i > n + 1)
                break;
            //평균 구하기
            double sum = 0;
            double avg = 0;
            double V = 0;
            for(int t = i;t < i+j;t++){
                sum += num[t];
            }
            avg = sum / (double)j;
            for(int t = i;t < i+j;t++){
                V += (num[t] - avg) * (num[t] - avg);
            }
            result = min(result, sqrt(V / j));
        }
    }
    cout.precision(11);
    cout << result;
}