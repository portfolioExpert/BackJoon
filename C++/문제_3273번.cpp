#include <iostream>
#include <algorithm>
using namespace std;

//문제 3273번 두 수의 합 -> 두 포인터, 정렬
int num[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    int x;
    cin >> x;
    sort(num, num + n);
    int result = 0;
    int left = 0;
    int right = n - 1;
    while(left < right){
        if(num[left] + num[right] < x){
            left++;
        }
        else if(num[left] + num[right] > x){
            right--;
        }
        else{
            left++;
            right--;
            result++;
        }
    }
    cout << result;
}