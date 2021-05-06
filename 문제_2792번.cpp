#include <iostream>
#include <algorithm>
using namespace std;

//문제 2792번
typedef long long ll;
ll color[300001], total, n;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll m,i , left = 1, right = -1 , mid, result =1000000001;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> color[i];
        right = max(color[i], right);//최대로 나누어 줄 수 있는 값을 지정 left는 최소 1개
    }
    while(left<=right){
        mid = (left + right)/2;//값을 맞춰가며 계속 나누어 줘본다
        total = 0;
        for(int i=0;i<m;i++){
            total += color[i] / mid;//보석을 일정 인원수 마다 나누어줄 수 있는지
            if(color[i] % mid)//나머지가 있으면
                total++;
        }
        if(n>=total){//구하는 값보다 이하값이면 되지만 아직 근접한 것은 아님
            result = min(result, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << result;
    return 0;
}