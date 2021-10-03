#include <iostream>
#include <algorithm>
using namespace std;

//문제 1406번
#include <list>
#include <string>
list <char> l;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string str;
    char ch, input;
    int n, i;
    cin >> str;
    for(i=0;i<str.size();i++){
        l.push_back(str[i]);
    }
    cin >> n;
    auto pos = l.end();//말단으로 처음 위치를 잡고 -> 커서를 의미
    for(i=0;i<n;i++){
        cin >> ch;
        if(ch == 'P'){
            cin >> input;
            l.insert(pos, input);//입력 받은 문자를 위치에 삽입하면 자동으로 연결
        }
        else if(ch == 'L'){
            if(pos != l.begin())//맨 앞이 아닐때 왼쪽으로 이동
                pos--;
        }
        else if(ch == 'D'){
            if(pos != l.end())//말단이 아닐때 오른쪽 이동
                pos++;
        }
        else if(ch == 'B'){
            if(pos != l.begin()){
                pos--;//지울때 커서 왠쪽을 지우므로
                pos = l.erase(pos);//지운 위치를 저장
            }
        }
    }
    for(char out : l){
        cout << out;
    }
    return 0;
}