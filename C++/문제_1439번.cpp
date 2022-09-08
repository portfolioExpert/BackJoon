//문제 1439번 뒤집기 -> 문자열, 구현
#include <string>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int zerocnt = 0;
    int onecnt = 0;
    string str;
    cin >> str;
    char before = str[0];
    if(before == '0')
        zerocnt++;
    else
        onecnt++;
    for(int i = 1;i<str.size();i++){
        if(before == str[i]){
            continue;
        }
        else{
            if(str[i] == '0')
                zerocnt++;
            else
                onecnt++;
        }
        before = str[i];
    }
    cout << min(zerocnt, onecnt);
}