//문제 9012번
#include <string>
#include <stack>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, i, j;
    cin >> n;
    for(i = 0;i<n;i++){
        string str;
        stack <char>s;
        cin >> str;
        for(j = 0;j<str.size();j++){
            if(str[j] == '(')
                s.push(str[j]);
            else{
                if(s.empty()){
                    break;
                }
                else
                    s.pop();
            }
        }
        if(s.empty() && j == str.size())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}