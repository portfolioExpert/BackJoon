#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//2104번 분할정복 풀이
typedef long long ll;
ll getmax(int from, int to);
ll num[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> num[i];
    }
    cout << getmax(1,n);
    return 0;
}
ll getmax(int from, int to){
    if(from == to)return num[from] * num[from];//시점과 종점이 같을때
    int center = (from+to) / 2;//분할정복을 위한 중간점 탐색
    ll left, right, leftresult, rightresult, result, sum = 0, minval;
    leftresult = getmax(from, center);//왼쪽에서 가장 큰 값
    rightresult = getmax(center+1, to);//오른쪽에서 가장 큰 값
    result = max(leftresult, rightresult);//둘중에 큰 값

    //여기부턴 중간을 포함할때
    left = center;//중간부터 왼쪽으로
    right = center + 1;//중간의 +1 오른쪽부터 오른쪽으로
    sum = (num[left] + num[right]);
    minval = min(num[left], num[right]);//둘중 작은 값
    result = max(result, minval * sum);//중간값과 비교 하여 큰값
    while(left > from || right < to){//중간부터 오른쪽, 또는 왼쪽으로 갈 것
        if(right < to && (left == from || num[left-1] < num[right + 1])){//왼쪽이 끝일때와 왼쪽값보다 오른쪽 값이 더 클때 진행
            sum+= num[++right];
            minval = min(minval, num[right]);
        }
        else{//나머진 왼쪽으로 진행
            sum+= num[--left];
            minval = min(minval, num[left]);
        }
        result = max(result, sum * minval);//3부분의 최종결과에서 가장 큰 값
    }
    return result;
}