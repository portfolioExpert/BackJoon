//문제 2470번 두 용액 -> 이분탐색
#include <cmath>
int num[100001];
int result = 2147483647;
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
    int left = 0, right = n - 1;
    int leftval = num[0], rightval = num[n-1];
    while(left < right){
        if(abs(result) > abs(num[left] + num[right])){
            leftval = num[left];
            rightval = num[right];
            result = abs(leftval + rightval);
        }
        if(abs(num[left]) > abs(num[right]))
            left++;
        else
            right--;
    }
    cout << leftval << " " << rightval;
}