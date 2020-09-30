#include <iostream>
#include <algorithm>
using namespace std;

//문제 10816번
int num1[500001], num2[500001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, i;
    cin >> n;
    for(i = 0;i<n;i++){
        cin >> num1[i];
    }
    cin >> m;
    for(i=0;i<m;i++){
        cin >> num2[i];
    }
    sort(num1, num1+n);
    for(i=0;i<m;i++){
//        cout <<upper_bound(num1, num1+n, num2[i]) - num1 << "\n" << lower_bound(num1, num1+n,num2[i]) - num1;
        //upper_bound는 num2[i]값을 처음으로 초과하는 인덱스
        //lower_bound는 num2[i]값이 처음으로 되는 인덱스
        //이것은 반환값은 포인터이므로 정확한 인덱스를 찾기위해서 배열 첫 포인터값을 빼줘야한다
        cout << upper_bound(num1, num1+n, num2[i]) - lower_bound(num1, num1+n,num2[i]) << "\n";
    }
    return 0;
}