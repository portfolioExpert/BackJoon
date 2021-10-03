//문제 4949번
#include <string>
#include <stack>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    while(1){
        int i;
        string str;
        getline(cin,str);
        if(str[0] == '.')break;
        stack <char>s;
        for(i = 0;i<str.size();i++){
            if(str[i] == '(' || str[i] == '[')
                s.push(str[i]);
            else if(str[i] == ')' || str[i] == ']'){
                if(!s.empty()){
                    if(str[i] == ')' && s.top() == '(')
                        s.pop();
                    else if(str[i] == ']' && s.top() == '[')
                        s.pop();
                    else
                        break;
                }
                else
                    break;
            }
        }
        if(s.empty() && i == str.size()){
            cout << "yes" <<"\n";
        }
        else
            cout << "no" << "\n";
    }
}