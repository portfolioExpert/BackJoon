//문제 5397번 키로거 -> 문자열, 스택
//틀린 이유: 왼쪽 스택과 오른쪽 스택의 비어있음을 문자와 동시에 체크
// 마지막 문자열을 합칠 때 한쪽으로 몰아서 해야했다.
#include <stack>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        string str;
        cin >> str;
        stack <char> left;
        stack <char> right;
        for(int j = 0;j<str.size();j++){
            if(str[j] == '<'){
                if(!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
            }
            else if(str[j] == '>'){
                if(!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
            }
            else if(str[j] == '-'){
                if(!left.empty())
                    left.pop();
            }
            else{
                left.push(str[j]);
            }
        }
        string result = "";

        while(!right.empty()){
            left.push(right.top());
            right.pop();
        }
        while(!left.empty()){
            result+=left.top();
            left.pop();
        }
        reverse(result.begin(), result.end());
        cout << result << "\n";
    }
}