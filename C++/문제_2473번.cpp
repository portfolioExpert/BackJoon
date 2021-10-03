//문제 2473번 세 용액 -> 이분탐색, 두 포인터
typedef long long ll;
#include <cmath>
ll num[5001];
ll result = 31474836470;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    sort(num, num + n);
    ll leftval = num[0], midval = num[(n-1) / 2] , rightval = num[n-1];
    for(int i = 0;i<n-2;i++){
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            //이부분에서 num을 ll으로 하지않으면 오버플로우가 나서 Num도 ll으로 해야한다
            ll total = num[i] + num[left] + num[right];
            if(result > abs(total)){
                leftval = num[i];
                midval = num[left];
                rightval = num[right];
                result = abs(total);
            }
            if(total < 0){
                left++;
            }
            else
                right--;
        }
    }
    cout << leftval << " " << midval << " " << rightval;
}