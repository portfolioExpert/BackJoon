#include <iostream>
#include <algorithm>
using namespace std;

//문제 13417번 카드 문자열 -> 덱
#include <deque>
int main(){
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        deque<char>dq;
        string str;
        getchar();
        getline(cin, str);
        dq.push_back(str[0]);
        for(int j = 1;j<str.size();j++){
            if(str[j] == ' ')
                continue;
            //앞은 가운데보다 작은거
            if(str[j] <= dq.front()){
                dq.push_front(str[j]);
            }
            else
                dq.push_back(str[j]);
        }
        while(!dq.empty()){
            cout << dq.front();
            dq.pop_front();
        }
        cout << "\n";
    }
}