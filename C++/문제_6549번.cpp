#include <iostream>
#include <algorithm>
using namespace std;
//문제 6549번 히스토그램에서 가장 큰 직사각형 -> 스택
#include <stack>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    while(1){
        long long result = 0;
        int n;
        cin >> n;
        if(n == 0)
            break;
        long long num[100001];
        for(int i = 0;i<n;i++){
            cin >> num[i];
        }
        num[n] = -1;//마지막까지 계산을 위해서 -1을 넣어준다.
        stack<long long>s;
        for(int i = 0;i<=n;i++){
            //이전 막대보다 작다면 계산
            while(!s.empty() && num[i] < num[s.top()]){
                long long weight;
                long long height = s.top();
                s.pop();

                //스택이 빈 거면 이전 막대들이 모두 작다는 것으로 그대로 너비를 i로
                if(s.empty()){
                    weight = i;
                }
                else
                    weight = i - s.top() - 1;

                result = max(result, num[height] * weight);
            }
            s.push(i);
        }
        cout << result << "\n";
    }
}