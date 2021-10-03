#include <iostream>
#include <algorithm>
using namespace std;

//문제 2217번
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tie[100001], result = -1;
    int n, i;
    cin >> n;
    for(i=0;i<n;i++){
        cin  >> tie[i];
    }
    sort(tie, tie+n);
    reverse(tie, tie+n);
    for(i=0;i<n;i++){
        if(tie[i] * (i+1) > result)//어차피 인덱스가 앞인 로프는 뒤에있는 로프의 하중을 견디기 때문에
            result = tie[i] * (i+1);
    }
    cout << result;
    return 0;
}