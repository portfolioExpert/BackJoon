#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//문제 10828번
#include <stack>
stack <int> s;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string ch;
    int n, i, num;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> ch;
        if(ch == "push"){
            cin >> num;
            s.push(num);
        }
        else if(ch == "top"){
            if(s.empty() == 1)cout << -1 << "\n";
            else
                cout << s.top() << "\n";
        }
        else if(ch == "size")
            cout << s.size() << "\n";
        else if(ch == "empty")
            cout << s.empty() << "\n";
        else if(ch == "pop"){
            if(s.empty() == 1)cout << -1 << "\n";
            else{
                cout << s.top() << "\n";
                s.pop();
            }
        }
    }
    return 0;
}