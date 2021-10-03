#include <iostream>
#include <algorithm>
using namespace std;

//문제 3649번
#define MAX 10000000
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, n, i, lego[1000001];
    while(cin >> t){//테스트케이스가 제한이 없는 문제라서 무한 루프를 돌려야한다 - 질문 검색 참고
        bool check = 0;
        cin >> n;
        for(i=0;i<n;i++){
            cin >> lego[i];
        }
        sort(lego, lego + n);
        int left = 0;
        int right = n-1;
        while(left < right && n >= 2){
            if(lego[left] + lego[right] == (t * MAX)){
                cout << "yes " << lego[left] << " " << lego[right] << "\n";
                check = 1;
                break;
            }
            else if(lego[left] + lego[right] > t * MAX){//여기도 MAX를 곱해야 했음
                right--;
            }
            else
                left++;
        }
        if(check == 0)
            cout << "danger" << "\n";
    }
    return 0;
}