#include <iostream>
#include <algorithm>
using namespace std;

//문제 20291번 파일 정리 -> 맵, 구현
#include <map>
map<string, int>m;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        string maker = "";
        bool flag = false;
        for(int j = 0;j<str.size();j++){
            if(flag)
                maker+=str[j];
            if(str[j] == '.')
                flag = true;
        }
        if(m[maker] == 0){
            m[maker] = 1;
        }
        else
            m[maker] = m[maker] + 1;
    }
    for(auto iter = m.begin();iter!=m.end();iter++)
        cout << iter->first << " " << iter->second << "\n";
}