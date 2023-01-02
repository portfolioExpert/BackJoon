//문제 1253번 좋다 -> 두 포인터, 정렬
//무조건 다 더해서 하면 어느 인덱스를 더했는지 모른다
#include <iostream>
#include <algorithm>
#include <vector>
int num[2001];
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
    int result = 0;
    for(int i = 0;i<n;i++){
        int left = 0;
        int right = n - 1;
        while(left < right){
            int sum = num[left] + num[right];
            if(sum < num[i]){
                left++;
            }
            else if(sum > num[i])
                right--;
            else{
                if(left != i && right != i){
                    result++;
                    break;
                }
                if(left == i)
                    left++;
                if(right == i)
                    right--;
            }
        }
    }
    cout << result;
}