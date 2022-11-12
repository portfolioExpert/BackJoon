#include <iostream>
#include <algorithm>
using namespace std;

//문제 1461번 도서관 -> 정렬, 그리디
//처리 해야하는 것
//1. 최대 들 수 있는 책 중 짧은 나머지 거리 /근데 최대길이가 짧은 걸로
#include <vector>
int num[51];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int>left;
    vector<int>right;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    sort(num, num + n);
    for(int i = 0;i<n;i++){
        if(num[i] > 0)
            right.push_back(num[i]);
    }
    for(int i = n - 1;i>=0;i--){
        if(num[i] < 0)
            left.push_back(-num[i]);
    }

    int result = 0;
    int leftidx = -1;
    int rightidx = -1;
    int maxval = -10001;
    //왼쪽나머지 처리
    if(leftidx < (int)left.size() && (int)left.size() % m > 0){
        result+= 2 * left[(int)left.size() % m - 1];
        leftidx+=(int)left.size() % m;
        maxval = max(maxval, left[(int)left.size() % m - 1]);
    }
    //오른쪽 나머지 처리
    if(rightidx < (int)right.size() && (int)right.size() % m > 0){
        result+= 2 * right[(int)right.size() % m - 1];
        rightidx+=(int)right.size() % m;
        maxval = max(maxval, right[(int)right.size() % m - 1]);
    }

    while(leftidx + m < (int)left.size() || rightidx + m < (int)right.size()){
        if(leftidx+m < left.size()){
            maxval = max(maxval, left[leftidx + m]);
            result+= 2 * left[leftidx + m];
            leftidx+=m;
        }
        if(rightidx + m  < right.size()){
            maxval = max(maxval, right[rightidx + m]);
            result+= 2 * right[rightidx + m];
            rightidx+=m;
        }
    }

    cout << result - maxval;
}