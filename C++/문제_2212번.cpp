//문제 2212번 센서 -> 그리디
#include <iostream>
#include <algorithm>
int sensor[10001];
int dis[10001];
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int result = 0;
    for(int i = 0;i<n;i++){
        cin >> sensor[i];
    }
    sort(sensor, sensor + n);
    //인접한 거리 차이를 봐야 전체 값이 최소가 되므로
    for(int i = 0;i<n-1;i++){
        dis[i] = sensor[i+1] - sensor[i];
    }
    sort(dis, dis + n - 1);
    //k개의 집중국을 설치하고 수신받아야할 것은 n-k개 이므로
    for(int i = 0;i<n - k;i++){
        result += dis[i];
    }
    cout << result;
}