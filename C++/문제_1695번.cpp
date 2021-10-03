#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 1695번
int num[5000];
int result[5000][5000];
int dp(int start, int end);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin  >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    cout << dp(0,n-1);
    return 0;
}
int dp(int start, int end){
    if(start >= end)return 0;
    if(result[start][end] != 0)return result[start][end];//값이 있으면 값을 리턴
    if(num[start] == num[end]){//끝값이 같으면 둘다 증가
        result[start][end]+=dp((start+1),(end-1));
    }
    else{//그 외 경우 왼쪽값을 이동, 오른쪽값을 이동한 것에서 최솟값을 저장
        result[start][end] += min(dp(start+1,end), dp(start,end-1))+1;
    }
    return result[start][end];
}