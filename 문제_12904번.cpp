//문제 12904번 A와B -> 문자열
//변경된 문자열에서 추적
#include <string>
string s, t;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> s >> t;
    int index = (int)t.size() - 1;
    while(s.size() < t.size()){
        //확인 후 제거부터
        char c = t[index];
        t = t.substr(0, t.size() - 1);
        index--;
        //B면 뒤집어 준다
        if(c == 'B'){
            reverse(t.begin(), t.end());
        }
    }
    if(t == s)
        cout << 1;
    else
        cout << 0;
}