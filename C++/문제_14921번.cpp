//문제 14921번 용액 합성하기 -> 투 포인터
#include <cmath>
int arr[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int left = 0, right = n - 1;
    int result = (arr[left] + arr[right]);
    while(left < right){
        if(abs(result) > abs(arr[left] + arr[right]))
            result = arr[left] + arr[right];
        if(abs(arr[left]) > abs(arr[right]))
            left++;
        else if(abs(arr[left]) < abs(arr[right])){
            right--;
        }
        //이 부분때문에 첫 틀림
        else{
            left++;
            right--;
        }
    }
    cout << result;
}