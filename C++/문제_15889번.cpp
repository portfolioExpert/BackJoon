#include <iostream>
#include <algorithm>
using namespace std;

//문제 15889번 호 안에 수류탄이야 -> 정렬
int pos[30001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> pos[i];
    }
    int len = 0, maxlen = 0;
    for(int i = 1;i<n;i++){
        cin >> len;
        maxlen = max(maxlen, pos[i - 1] + len);
        if(maxlen < pos[i]){
            cout <<"엄마 나 전역 늦어질 것 같아";
            return 0;
        }
    }
    cout << "권병장님, 중대장님이 찾으십니다";
}
/*
 4
 0 10 20 30
 20 5 10
 */