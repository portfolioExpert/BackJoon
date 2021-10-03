#include <iostream>
#include <algorithm>
using namespace std;

//문제 1874번
#include <stack>
stack <int> s;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, arr[100001], t = 0, in = 1, k = 0;
    char ch[100001];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    while(1){
        for(i = in;i<=arr[t];i++){
            s.push(i);
            ch[k++] = '+';//스택에 넣을때마다 부호도 넣고
        }
        in = arr[t] + 1;//in은 스택에 넣을 수를 저장
        while(!s.empty()&&arr[t] == s.top() && t <= n){
            s.pop();
            ch[k++] = '-';
            t++;
        }
        if(t >= n)break;
        if(!s.empty() && s.top() > arr[t]){//스택 탑이 꺼내야할 수 보다 클경우 수열이 안되므로 NO출력
            cout << "NO";
            return 0;
        }
    }
    for(i=0;i<k;i++){//정상적으로 될때 출력
        cout << ch[i] << "\n";
    }
    return 0;
}