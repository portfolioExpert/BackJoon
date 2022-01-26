//문제 10773번 제로 -> 스택
#include <stack>
int main(){
    int n;
    cin >> n;
    stack<int>s;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(num == 0)
            s.pop();
        else
            s.push(num);
    }
    int sum = 0;
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout << sum;
}