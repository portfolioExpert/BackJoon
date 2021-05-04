#include <iostream>
#include <algorithm>
using namespace std;

//문제 6236번
bool fx(int mid);
int money[100001], n, m;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int i, left = 1, right = -1, mid = 0, total = 0 ,result = 0;
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> money[i];
        total +=money[i];//1번에 끝낼 경우를 위해서
    }
    right = total;
    while(left <= right){
        mid = (left+right)/2;
        if(fx(mid)){
            result = mid;//
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << result;
    return 0;
}
bool fx(int mid){
    int sum = 1, save = mid, i;
    for(i = 0;i<n;i++){
        if(mid < money[i]){//이것 때문에 함수를 만듬
            return 0;
        }
        if(save - money[i] < 0){
            sum++;
            save = mid;
        }
        save-= money[i];
    }
    return m>=sum;//뽑아야할 양보다 적을 경우 right를 조정하기 위해서 >부호를 붙여줌
}