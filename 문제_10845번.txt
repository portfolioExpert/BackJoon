#include <iostream>
#include <algorithm>
using namespace std;

//문제 10845번
#include <queue>
queue <int> q;
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
            q.push(num);
        }
        else if(ch == "pop"){
            if(q.empty() == 1)
                cout << -1 << "\n";
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(ch == "size")
            cout << q.size() << "\n";
        else if(ch == "empty")
            cout << q.empty() << "\n";
        else if(ch == "front"){
            if(q.empty() == 1)cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if(ch == "back"){
            if(q.empty() == 1)cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }
    return 0;
}