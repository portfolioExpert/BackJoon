#include <iostream>
#include <algorithm>
using namespace std;

//문제 16434번
typedef long long ll;
ll atk, n, room[123457][3];
bool fx(ll mid);
int main(){
    ll i, left = 1, mid, right = 1, result = 0;
    cin >> n >> atk;
    ll reatk = atk;
    for(i=0;i<n;i++){
        cin >> room[i][0] >> room[i][1] >>room[i][2];
        if(room[i][0] == 1){
            right+=(room[i][2] / reatk * room[i][1]);
            if(!(room[i][2] % reatk))//딱 맞게 죽는 경우 내가 한대를 안맞아도됨
                right-=room[i][1];
        }
        else
            reatk+=room[i][1];
    }
    while(left <= right){
        mid = (left+right)/2;
        if(fx(mid)){
            right = mid - 1;
            result = mid;
        }
        else
            left = mid + 1;
    }
    cout << result;
    return 0;
}
bool fx(ll mid){
    ll save = mid, myatk, i;
    myatk = atk;
    for(i=0;i<n;i++){
        if(room[i][0] == 1){
            save-= room[i][2] / myatk * room[i][1];
            if(!(room[i][2] % myatk))//딱 맞게 죽는 경우 한대를 덜 맞음
                save+=room[i][1];
        }
        else{
            save+= room[i][2];
            if(save > mid)
                save = mid;
            myatk+=room[i][1];
        }
        if(save <= 0)//여기서 =가 있고 없고 때문에 1 차이 났음
            return 0;
    }
    return save > 0;
}