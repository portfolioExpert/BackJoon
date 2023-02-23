#include <iostream>
#include <algorithm>
using namespace std;

//문제 2485번 가로수 -> 유클리드 호제법
int num[100001];
int dis[100001];
int gcd(int maxval, int minval){
    while(minval > 0){
        int save = maxval % minval;
        maxval = minval;
        minval = save;
    }
    return maxval;
}
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
    for(int i = 0;i<n - 1;i++){
        dis[i] = num[i + 1] - num[i];
    }
    long long result = 0;
    int modular = dis[0];
    //공약수
    for(int i = 0;i<n;i++){
        modular = gcd(modular, dis[i]);
    }
    for(int i = 0;i<n-1;i++){
        result+= dis[i] / modular - 1;
    }
    cout << result;
}